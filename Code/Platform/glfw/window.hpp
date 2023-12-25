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

        void register_user_pointer()  final;
        void register_size_callback() final;

        bool is_closed() final;

    private:
        GLFWwindow* _handle;
    };
}