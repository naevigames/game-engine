#include "window_callbacks.hpp"
#include "platform_manager.hpp"
#include "screen.hpp"

namespace glfw
{
    void WindowCallbacks::on_size_callback(GLFWwindow*, int32_t width, int32_t height)
    {
        Screen::set_size({ width, height });
    }

    void WindowCallbacks::on_close_callback(GLFWwindow*)
    {
        PlatformManager::instance().shutdown();
    }
}