#pragma once

#include "window_size.hpp"

namespace base
{
    struct window_config
    {
        std::string title;
        window_size size;

        bool vulkan_api;
    };
}