#pragma once

#include "surface.hpp"
#include "surface_details.hpp"
#include "queue_indices.hpp"

namespace vk
{
    class PhysicalDevice final : public base::Object<VkPhysicalDevice>
    {
    public:
        void get_queue_indices(const   Surface& surface);
        void get_surface_details(const Surface& surface);

        QueueIndices   queue_indices;
        SurfaceDetails surface_details;
    };
}