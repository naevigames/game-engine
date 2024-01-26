#pragma once

#include "device.hpp"

namespace vk
{
    class ImageView final : public base::Object<VkImageView>
    {
    public:
        void create(const  Device& device, const VkImage& image, const VkFormat& format);
        void destroy(const Device& device);
    };
}