#include "callbacks.hpp"

namespace glfw
{
    void Callbacks::size_callback(GLFWwindow* handle, int32_t width, int32_t height)
    {
        window::Screen::set_size(width, height);
    }
}