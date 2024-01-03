#pragma once

#include "instance.hpp"

namespace vk
{
    class Surface final : public base::Object<VkSurfaceKHR>
    {
    public:
        void create(const  Instance& instance, HWND handle);
        void release(const Instance& instance);

        [[nodiscard]] VkSurfaceKHR handle() const; // TODO remove in the future?
    };
}