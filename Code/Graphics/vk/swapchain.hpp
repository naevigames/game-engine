#pragma once

#include "surface.hpp"
#include "device.hpp"
#include "image_view.hpp"

namespace vk
{
    class Swapchain final : public base::Object<VkSwapchainKHR>
    {
    public:
        void create(const  Device& device, const PhysicalDevice& physical_device, const Surface& surface);
        void destroy(const Device& device);

        void get_images(const Device& device, const VkFormat& format);

        VkImage  image(uint32_t index) const;
        uint32_t images_count;

    private:
        std::vector<ImageView> _views;
        std::vector<VkImage>   _images;
    };
}