#pragma once

#include "instance.hpp"

namespace vk
{
    class Surface final : public base::Object<VkSurfaceKHR>
    {
    public:
        void create(const  Instance& instance, std::any handle);
        void destroy(const Instance& instance);
    };
}