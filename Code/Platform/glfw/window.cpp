#include "window.hpp"
#include "callbacks.hpp"
#include "screen.hpp"

namespace glfw
{
    Window::Window()
        : _handle { }
    {
    }

    void Window::create(const base::window_config& config)
    {
            _handle =  glfwCreateWindow(config.size.width,
                                        config.size.height, config.title.c_str(), nullptr);
        if (_handle == nullptr)
        {
            std::exit(EXIT_FAILURE);
        }

        Screen::set_size(config.size);
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

    void Window::hint(const base::window_hint& hint)
    {
        glfwWindowHint(hint.first, hint.second);
    }

    void Window::register_user_pointer()
    {
        glfwSetWindowUserPointer(_handle, (void*)this);
    }

    void Window::register_size_callback()
    {
        glfwSetFramebufferSizeCallback(_handle, Callbacks::size_callback);
    }

    void Window::register_close_callback()
    {
        glfwSetWindowCloseCallback(_handle, Callbacks::close_callback);
    }
}