#pragma once

#include "window_hint.hpp"
#include "window_config.hpp"

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
        virtual void sync_buffers() const = 0;

        virtual void register_user_pointer()
        {
        }
        virtual void register_size_callback()
        {
        };
        virtual void register_close_callback()
        {
        };

        virtual void hint(const window_hint& hint) = 0;
    };
}