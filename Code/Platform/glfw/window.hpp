#pragma once

#include "core/window.hpp"

namespace glfw
{
    class Window final : core::Window
    {
    public:
        Window();

        void create(const window::config& config) final;
        void destroy() final;

        void activate() final;
        void close()    final;

        void swap_buffers() final;

        void hint(const window::hint& hint) final;

        void register_resize_callback() final;

        bool is_closed() final;

    private:
        static void resize_callback(GLFWwindow* handle, int32_t width, int32_t height);

    private:
        GLFWwindow* _handle;
    };
}