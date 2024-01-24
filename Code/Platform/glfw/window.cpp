#include "window.hpp"

namespace glfw
{
    bool Window::create()
    {
               _handle = glfwCreateWindow(800, 600, "", nullptr, nullptr);
        return _handle != nullptr;
    }

    void Window::destroy()
    {
    }
}