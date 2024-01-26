#include "queue.hpp"

namespace vk
{
    void Queue::find_queue(const Device& device, uint32_t family_index)
    {
        vkGetDeviceQueue(device._handle, family_index, 0, &_handle);
    }

    void Queue::submit(const VkCommandBuffer& command_buffer)
    {
        VkSubmitInfo submit_info
        {
            .sType = VK_STRUCTURE_TYPE_SUBMIT_INFO,
            .commandBufferCount = 1,
            .pCommandBuffers    = &command_buffer
        };

        vkQueueSubmit(_handle, 1, &submit_info, nullptr);
    }

    void Queue::present(const Swapchain& swapchain, uint32_t image_index)
    {
        VkPresentInfoKHR vk_present_info
        {
            .sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR,
            .swapchainCount = 1,
            .pSwapchains    = &swapchain._handle,
            .pImageIndices  = &image_index
        };

        vkQueuePresentKHR(_handle, &vk_present_info);
    }
}