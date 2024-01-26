#pragma once

#include "physical_device.hpp"

namespace vk
{
    class Queue;
    class Device final : public base::Object<VkDevice>
    {
    public:
        void create(const PhysicalDevice& physical_device);
        void destroy();

        [[nodiscard]] Queue get_queue(uint32_t family_index) const;
    };
}