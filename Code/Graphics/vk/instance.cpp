#include "instance.hpp"
#include "physical_device.hpp"

namespace vk
{
    void Instance::create()
    {
        std::array<const char*, 2> instance_extensions
        {
            "VK_KHR_surface",
            "VK_KHR_win32_surface"
        };

        VkApplicationInfo application_info
        {
            .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
            .pApplicationName = "NextGameEngine",
            .pEngineName      = "NextGameEngine",
            .apiVersion       = VK_API_VERSION_1_0
        };

        VkInstanceCreateInfo instance_create_info
        {
            .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
            .pApplicationInfo        = &application_info,
            .enabledLayerCount       = 0,
            .enabledExtensionCount   = static_cast<int32_t>(instance_extensions.size()),
            .ppEnabledExtensionNames = instance_extensions.data()
        };

        vkCreateInstance(&instance_create_info, nullptr, &_handle);
    }

    void Instance::destroy()
    {
        vkDestroyInstance(_handle, nullptr);
    }

    PhysicalDevice Instance::find_device() const
    {
        uint32_t physical_device_count;
        vkEnumeratePhysicalDevices(_handle, &physical_device_count, nullptr);

        std::vector<VkPhysicalDevice> physical_devices(physical_device_count);
        vkEnumeratePhysicalDevices(_handle, &physical_device_count, physical_devices.data());

        PhysicalDevice   physical_device;
        physical_device._handle = physical_devices[0];

        return physical_device;
    }
}