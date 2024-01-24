#pragma once

#include "base/window.hpp"

namespace glfw
{
    class Window final : public base::Window
    {
    public:
        Window();

        bool create(const base::window_config& config) final;
        void destroy()                                 final;
        void activate()                                final;

        void swap_buffers()      const final;

        void register_user_pointer()   final;
        void register_size_callback()  final;
        void register_close_callback() final;

        void hint(const base::window_hint& hint) final;

    private:
        GLFWwindow* _handle;
    };
}