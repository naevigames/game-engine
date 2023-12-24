#include "window.hpp"
#include "callbacks.hpp"

namespace glfw
{
    Window::Window()
        : _handle { }
    {
    }

    void Window::create(const window::config& config)
    {
            _handle =  glfwCreateWindow(config.width, config.height, config.title.c_str(), nullptr);
        if (_handle == nullptr)
        {
            exit(EXIT_FAILURE);
        }

        window::Screen::set_size(config.width, config.height);
    }

    void Window::destroy()
    {
        glfwDestroyWindow(_handle);
    }

    void Window::swap_buffers() const
    {
        glfwSwapBuffers(_handle);
    }

    void Window::activate()
    {
        glfwMakeContextCurrent(_handle);
    }

    void Window::close()
    {
        glfwSetWindowShouldClose(_handle, GLFW_TRUE);
    }

    void Window::hint(const window::param& hint)
    {
        glfwWindowHint(hint.flag, hint.value);
    }

    void Window::register_user_pointer()
    {
        glfwSetWindowUserPointer(_handle, (void*)this);
    }

    void Window::register_size_callback()
    {
        glfwSetFramebufferSizeCallback(_handle, Callbacks::size_callback);
    }

    bool Window::is_closed()
    {
        return glfwWindowShouldClose(_handle);
    }
}