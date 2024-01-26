#include "swapchain.hpp"

namespace vk
{
    void Swapchain::create(const Device& device, const Surface& surface, const SurfaceDetails& details, const QueueIndices& indices)
    {
        VkSwapchainCreateInfoKHR swapchain_create_info
        {
            .sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR,
            .surface          = surface._handle,
            .minImageCount    = details.capabilities.minImageCount,
            .imageFormat      = details.format.format,
            .imageColorSpace  = details.format.colorSpace,
            .imageExtent      = details.capabilities.currentExtent,
            .imageArrayLayers = 1,
            .imageUsage       = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
            .preTransform     = details.capabilities.currentTransform,
            .compositeAlpha   = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,
            .presentMode      = VK_PRESENT_MODE_FIFO_KHR,
            .clipped          = VK_TRUE,
            .oldSwapchain     = VK_NULL_HANDLE
        };

        if (indices.set().size() > 1)
        {
            auto family_indices = indices.vec();

            swapchain_create_info.imageSharingMode      = VK_SHARING_MODE_CONCURRENT;
            swapchain_create_info.queueFamilyIndexCount = static_cast<uint32_t>(family_indices.size()),
            swapchain_create_info.pQueueFamilyIndices   = family_indices.data();
        }
        else
        {
            swapchain_create_info.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
        }

        vkCreateSwapchainKHR(device._handle, &swapchain_create_info, nullptr, &_handle);
    }

    void Swapchain::destroy(const Device& device)
    {
        vkDestroySwapchainKHR(device._handle, _handle, nullptr);
    }
}