#pragma once

#include "surface.hpp"
#include "queue_indices.hpp"

namespace vk
{
    class PhysicalDevice final : public base::Object<VkPhysicalDevice>
    {
    public:
        void find_device(const Instance& instance);
        void find_queue(const  Surface&  surface);

        QueueIndices queue_indices;
    };
}