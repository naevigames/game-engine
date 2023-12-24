#pragma once

#include "core/window.hpp"

namespace glfw
{
    class Window final : public core::Window
    {
    public:
        Window();

        void create(const window::config& config) final;
        void destroy()  final;

        void activate() final;
        void close()    final;

        void swap_buffers() const final;

        void hint(const window::param& hint) final;

        void register_size_callback() final;

        bool is_closed() final;

    private:
        static void size_callback(GLFWwindow* handle, int32_t width, int32_t height);

    private:
        GLFWwindow* _handle;
    };
}