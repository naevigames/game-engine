#pragma once

#include "physical_device.hpp"

namespace vk
{
    class Device final : public base::Object<VkDevice>
    {
    public:
        void create(const PhysicalDevice& physical_device);
        void destroy();
    };
}