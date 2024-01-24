#include "window.hpp"

namespace glfw
{
    Window::Window()
        : _handle { }
    {
    }

    bool Window::create(const base::window_config& config)
    {
               _handle = glfwCreateWindow(config.size.width, config.size.height, config.title.c_str(), nullptr, nullptr);
        return _handle != nullptr;
    }

    void Window::destroy()
    {
        glfwDestroyWindow(_handle);
    }

    void Window::activate()
    {
        glfwMakeContextCurrent(_handle);
    }

    void Window::swap_buffers() const
    {
        glfwSwapBuffers(_handle);
    }

    void Window::register_user_pointer()
    {
    }

    void Window::register_size_callback()
    {
    }

    void Window::register_close_callback()
    {
    }

    void Window::hint(const base::window_hint& hint)
    {
    }
}