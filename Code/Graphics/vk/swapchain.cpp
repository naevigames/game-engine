#include "swapchain.hpp"

namespace vk
{
    void Swapchain::create(const Device& device, const PhysicalDevice& physical_device, const Surface& surface)
    {
        auto details = physical_device.surface_details;
        auto indices = physical_device.queue_indices;

        VkSwapchainCreateInfoKHR swapchain_create_info
        {
            .sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR,
            .surface          = surface._handle,
            .minImageCount    = details.capabilities.minImageCount,
            .imageFormat      = details.current_format.format,
            .imageColorSpace  = details.current_format.colorSpace,
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
        for (auto view : _views)
        {
            view.destroy(device);
        }

        vkDestroySwapchainKHR(device._handle, _handle, nullptr);
    }

    void Swapchain::get_images(const Device& device, const VkFormat& format)
    {
        vkGetSwapchainImagesKHR(device._handle, _handle, &images_count, nullptr);
        _images.resize(images_count);

        vkGetSwapchainImagesKHR(device._handle, _handle, &images_count, _images.data());
        _views.resize(images_count);

        for (int32_t i = 0; i < images_count; i++)
        {
            _views[i].create(device, _images[i], format);
        }
    }

    VkImage Swapchain::image(uint32_t index) const
    {
        return _images[index];
    }
}