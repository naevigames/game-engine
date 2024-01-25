#include "device.hpp"

namespace vk
{
    void Device::create(const PhysicalDevice& physical_device)
    {
        float queue_priority = 1.0f;

        std::array<const char*, 1> device_extensions
        {
            VK_KHR_SWAPCHAIN_EXTENSION_NAME
        };

        std::set<uint32_t> unique_queue_families =
        {
            physical_device.graphics_queue_index,
            physical_device.present_queue_index
        };

        std::vector<VkDeviceQueueCreateInfo> queue_create_info_list;

        for (uint32_t queue_family : unique_queue_families)
        {
            queue_create_info_list.push_back({
                .sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
                .queueFamilyIndex = queue_family,
                .queueCount       = 1,
                .pQueuePriorities = &queue_priority
            });
        }

        VkPhysicalDeviceFeatures device_features
        {
        };

        VkDeviceCreateInfo device_create_info
        {
            .sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
            .queueCreateInfoCount    = static_cast<uint32_t>(queue_create_info_list.size()),
            .pQueueCreateInfos       = queue_create_info_list.data(),
            .enabledExtensionCount   = static_cast<int32_t>(device_extensions.size()),
            .ppEnabledExtensionNames = device_extensions.data(),
            .pEnabledFeatures        = &device_features
        };

        vkCreateDevice(physical_device._handle, &device_create_info, nullptr, &_handle);
    }

    void Device::destroy()
    {
        vkDestroyDevice(_handle, nullptr);
    }
}