#include "image_view.hpp"

namespace vk
{
    void ImageView::create(const Device& device, const VkImage& image, const VkFormat& format)
    {
        VkImageViewCreateInfo image_view_create_info
        {
            .sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            .image            = image,
            .viewType         = VK_IMAGE_VIEW_TYPE_2D,
            .format           = format,
            .components       = { VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY },
            .subresourceRange = { VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 },
        };

        vkCreateImageView(device._handle, &image_view_create_info, nullptr, &_handle);
    }

    void ImageView::destroy(const Device& device)
    {
        vkDestroyImageView(device._handle, _handle, nullptr);
    }
}