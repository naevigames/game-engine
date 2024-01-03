#include "instance.hpp"

namespace vk
{
    void Instance::create()
    {
        const char* extensions[2]
        {
            "VK_KHR_surface",
            "VK_KHR_win32_surface"
        };

        VkApplicationInfo app_info
        {
            .sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO,
            .pApplicationName   = "Template",
            .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
            .pEngineName        = "No Engine",
            .engineVersion      = VK_MAKE_VERSION(1, 0, 0),
            .apiVersion         = VK_API_VERSION_1_0
        };

        VkInstanceCreateInfo create_info
        {
            .sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
            .pApplicationInfo        = &app_info,
            .enabledLayerCount       = 0,
            .enabledExtensionCount   = 2,
            .ppEnabledExtensionNames = extensions
        };

        vkCreateInstance(&create_info, nullptr, &_handle);
    }

    void Instance::release()
    {
        vkDestroyInstance(_handle, nullptr);
    }

    VkInstance Instance::handle() const
    {
        return _handle;
    }
}