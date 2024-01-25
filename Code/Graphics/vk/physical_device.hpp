#pragma once

#include "surface.hpp"

namespace vk
{
    class PhysicalDevice final : public base::Object<VkPhysicalDevice>
    {
    public:
        void find_device(const Instance& instance);
        void find_queue(const  Surface&  surface);

        uint32_t graphics_queue_index = -1;
        uint32_t present_queue_index  = -1;
    };
}