#pragma once

#include "window_config.hpp"
#include "window_hint.hpp"

namespace base
{
    class Window
    {
    public:
        virtual bool create(const window_config& config) = 0;
        virtual void destroy()                           = 0;
        virtual void activate()                          = 0;

        virtual void swap_buffers() const
        {
        }

        virtual void register_user_pointer()
        {
        }
        virtual void register_size_callback()
        {
        }
        virtual void register_close_callback()
        {
        }

        virtual void     hint(const window_hint& hint)
        {
        } // TODO move this to platform
        virtual std::any handle() const = 0;

        virtual ~Window() = default;
    };
}