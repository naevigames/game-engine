#pragma once

#include "swapchain.hpp"

namespace vk
{
    class Queue final : public base::Object<VkQueue>
    {
    public:
        void submit(const  VkCommandBuffer& command_buffer);
        void present(const Swapchain& swapchain, uint32_t image_index);
    };
}