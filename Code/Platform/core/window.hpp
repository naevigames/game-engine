#pragma once

#include "window/hint.hpp"
#include "window/config.hpp"

namespace core
{
    class Window
    {
        virtual void create(const window::config& config) = 0;
        virtual void destroy() = 0;

        virtual void activate() = 0;
        virtual void close()    = 0;

        virtual void swap_buffers() = 0;

        virtual void hint(const window::hint& hint) = 0;

        virtual void register_resize_callback() = 0;

        virtual bool is_closed() = 0;
    };
}