#include "callbacks.hpp"
#include "platform_manager.hpp"
#include "screen.hpp"

namespace glfw
{
    void Callbacks::size_callback(GLFWwindow*, int32_t width, int32_t height)
    {
        window::Screen::set_size(width, height);
    }

    void Callbacks::close_callback(GLFWwindow*)
    {
        PlatformManager::instance().shutdown();
    }
}