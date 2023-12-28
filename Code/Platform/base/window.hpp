#pragma once

#include "window_hint.hpp"
#include "window_config.hpp"
#include "window_screen.hpp"

namespace base
{
    class Window
    {
    public:
        virtual ~Window() = default;

        virtual void create(const window_config& config) = 0;
        virtual void destroy()  = 0;
        virtual void activate() = 0;

        virtual void swap_buffers() const = 0;

        virtual void register_user_pointer()   = 0;
        virtual void register_size_callback()  = 0;
        virtual void register_close_callback() = 0;

        virtual void hint(const window_hint& hint) = 0;
    };
}