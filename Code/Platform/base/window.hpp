#pragma once

#include "window/param.hpp"
#include "window/config.hpp"
#include "window/screen.hpp"

namespace base
{
    class Window
    {
    public:
        virtual ~Window() = default;

        virtual void create(const window::config& config) = 0;
        virtual void destroy()  = 0;

        virtual void activate() = 0;
        virtual void close()    = 0;

        virtual void swap_buffers() const = 0;

        virtual void hint(const window::param& hint) = 0;

        virtual void register_user_pointer()  = 0;
        virtual void register_size_callback() = 0;

        virtual bool is_closed() = 0;
    };
}