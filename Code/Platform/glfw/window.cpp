#include "window.hpp"

namespace glfw
{
    Window::Window()
        : _handle { }
    {
    }

    void Window::create(window_config& config)
    {
        _handle = glfwCreateWindow(config.width, config.height, config.title.c_str(), nullptr, nullptr);

        if (_handle == nullptr)
        {
            exit(EXIT_FAILURE);
        }
    }

    void Window::destroy()
    {
        glfwDestroyWindow(_handle);
    }

    void Window::swap_buffers()
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

    void Window::hint(window_hint hint)
    {
        glfwWindowHint(hint.flag, hint.value);
    }

    void Window::register_resize_callback()
    {
        glfwSetWindowUserPointer(_handle, (void*)this);
        glfwSetFramebufferSizeCallback(_handle, resize_callback);
    }

    bool Window::is_closed()
    {
        return glfwWindowShouldClose(_handle) == GLFW_TRUE;
    }

    void Window::resize_callback(GLFWwindow* handle, int32_t width, int32_t height)
    {
        WindowScreen::resize(width, height);
    }
}