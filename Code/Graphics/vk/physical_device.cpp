#include "physical_device.hpp"

namespace vk
{
    void PhysicalDevice::get_queue_indices(const Surface& surface)
    {
        uint32_t queue_family_count;
        vkGetPhysicalDeviceQueueFamilyProperties(_handle, &queue_family_count, nullptr);

        std::vector<VkQueueFamilyProperties> queue_families(queue_family_count);
        vkGetPhysicalDeviceQueueFamilyProperties(_handle, &queue_family_count, queue_families.data());

        for (int32_t i = 0; i < queue_family_count; i++)
        {
            VkBool32 present_available;
            vkGetPhysicalDeviceSurfaceSupportKHR(_handle, i, surface._handle, &present_available);

            if (present_available)
            {
                queue_indices._present = i;
            }

            if (queue_families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
            {
                queue_indices._graphics = i;
            }

            if (queue_indices._graphics != -1 && queue_indices._present != -1)
            {
                break;
            }
        }
    }

    void PhysicalDevice::get_surface_details(const Surface& surface)
    {
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(_handle, surface._handle, &surface_details.capabilities);

        uint32_t vk_surface_format_count;
        vkGetPhysicalDeviceSurfaceFormatsKHR(_handle, surface._handle, &vk_surface_format_count, nullptr);

        std::vector<VkSurfaceFormatKHR> vk_surface_formats(vk_surface_format_count);
        vkGetPhysicalDeviceSurfaceFormatsKHR(_handle, surface._handle, &vk_surface_format_count, vk_surface_formats.data());

        surface_details.current_format = vk_surface_formats[0];
    }
}