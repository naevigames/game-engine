#pragma once

#include "device.hpp"

namespace vk
{
    class Queue final : public base::Object<VkQueue> // TODO this should not have a separate class?
    {
    public:
        void find_queue(const Device& device, uint32_t family_index);
    };
}