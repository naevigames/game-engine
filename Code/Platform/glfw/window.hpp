#pragma once

#include "base/window.hpp"

namespace glfw
{
    class Window final : public base::Window
    {
    public:
        Window();

        void create(const window::config& config) final;
        void destroy()  final;
        void activate() final;

        void swap_buffers() const final;

        void hint(const window::param& hint) final;

        void register_user_pointer()   final;
        void register_size_callback()  final;
        void register_close_callback() final;

    private:
        GLFWwindow* _handle;
    };
}