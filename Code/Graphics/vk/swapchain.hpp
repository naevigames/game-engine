#pragma once

#include "surface.hpp"
#include "surface_details.hpp"
#include "device.hpp"

namespace vk
{
    class Swapchain final : public base::Object<VkSwapchainKHR>
    {
    public:
        void create(const  Device& device, const Surface& surface, const SurfaceDetails& details, const QueueIndices& indices);
        void destroy(const Device& device);
    };
}