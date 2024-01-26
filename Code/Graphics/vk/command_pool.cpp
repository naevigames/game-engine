#include "command_pool.hpp"
#include "device.hpp"

namespace vk
{
    void CommandPool::create(const Device& device, uint32_t queue_index)
    {
        VkCommandPoolCreateInfo command_pool_create_info
        {
            .sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
            .queueFamilyIndex = queue_index,
        };

        vkCreateCommandPool(device._handle, &command_pool_create_info, nullptr, &_handle);
    }

    void CommandPool::destroy(const Device& device)
    {
        vkDestroyCommandPool(device._handle, _handle, nullptr);
    }
}