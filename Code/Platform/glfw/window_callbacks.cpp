#include "window_callbacks.hpp"
#include "window_manager.hpp"

namespace glfw
{
    void WindowCallbacks::on_size_callback(GLFWwindow*, int32_t width, int32_t height)
    {
    }

    void WindowCallbacks::on_close_callback(GLFWwindow*)
    {
        WindowManager::instance().shutdown();
    }
}