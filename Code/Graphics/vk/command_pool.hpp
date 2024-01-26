#pragma once

#include "base/object.hpp"

namespace vk
{
    class Device;
    class CommandPool final : public base::Object<VkCommandPool>
    {
    public:
        void create(const  Device& device, uint32_t queue_index);
        void destroy(const Device& device);
    };
}