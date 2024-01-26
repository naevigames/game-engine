#pragma once

#include "swapchain.hpp"

namespace vk
{
    class Queue final : public base::Object<VkQueue>
    {
    public:
        void find_queue(const Device& device, uint32_t family_index);

        void submit(const VkCommandBuffer& command_buffer);
        void present(const Swapchain& swapchain, uint32_t image_index);
    };
}