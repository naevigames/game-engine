#pragma once

#include "window_config.hpp"
#include "window_hint.hpp"

namespace core
{
    class Window
    {
        virtual void create(const window_config& config) = 0;
        virtual void destroy() = 0;

        virtual void activate() = 0;
        virtual void close()    = 0;

        virtual void swap_buffers() = 0;

        virtual void hint(const window_hint& hint) = 0;

        virtual void register_resize_callback() = 0;

        virtual bool is_closed() = 0;
    };
}