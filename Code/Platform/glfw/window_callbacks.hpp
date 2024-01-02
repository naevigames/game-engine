#pragma once

namespace glfw
{
    class WindowCallbacks
    {
    public:
        WindowCallbacks() = delete;

        static void on_size_callback(GLFWwindow*, int32_t width, int32_t height);
        static void on_close_callback(GLFWwindow*);
    };
}