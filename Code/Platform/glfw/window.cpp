#include "window.hpp"

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

    void Window::register_size_callback()
    {
        glfwSetWindowUserPointer(_handle, (void*)this);
        glfwSetFramebufferSizeCallback(_handle, size_callback);
    }

    bool Window::is_closed()
    {
        return glfwWindowShouldClose(_handle);
    }

    void Window::size_callback(GLFWwindow* handle, int32_t width, int32_t height)
    {
        window::Screen::set_size(width, height);
    }
}