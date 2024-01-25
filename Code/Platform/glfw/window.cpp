#include "window.hpp"
#include "window_callbacks.hpp"

namespace glfw
{
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
        glfwSetWindowUserPointer(_handle, (void*)this);
    }

    void Window::register_size_callback()
    {
        glfwSetFramebufferSizeCallback(_handle, WindowCallbacks::on_size_callback);
    }

    void Window::register_close_callback()
    {
        glfwSetWindowCloseCallback(_handle, WindowCallbacks::on_close_callback);
    }

    void Window::hint(const base::window_hint& hint)
    {
        glfwWindowHint(hint.first, hint.second);
    }

    std::any Window::handle() const
    {
        return _handle;
    }
}