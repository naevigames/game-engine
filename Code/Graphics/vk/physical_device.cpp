#include "physical_device.hpp"

namespace vk
{
    void PhysicalDevice::find_device(const Instance& instance)
    {
        uint32_t physical_device_count;
        vkEnumeratePhysicalDevices(instance._handle, &physical_device_count, nullptr);

        std::vector<VkPhysicalDevice> physical_devices(physical_device_count);
        vkEnumeratePhysicalDevices(instance._handle, &physical_device_count, physical_devices.data());

        _handle = physical_devices[0];
    }

    void PhysicalDevice::find_queue(const Surface& surface)
    {
        uint32_t queue_family_count;
        vkGetPhysicalDeviceQueueFamilyProperties(_handle, &queue_family_count, nullptr);

        std::vector<VkQueueFamilyProperties> queue_families(queue_family_count);
        vkGetPhysicalDeviceQueueFamilyProperties(_handle, &queue_family_count, queue_families.data());

        for (int32_t i = 0; i < queue_family_count; i++)
        {
            if (queue_families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
            {
                graphics_queue_index = i;
            }

            VkBool32 present_available;
            vkGetPhysicalDeviceSurfaceSupportKHR(_handle, i, surface._handle, &present_available);

            if (present_available)
            {
                present_queue_index = i;
            }

            if (graphics_queue_index != -1 && present_queue_index != -1)
            {
                break;
            }
        }
    }
}