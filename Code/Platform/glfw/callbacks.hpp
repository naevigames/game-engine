#pragma once

#include "window/screen.hpp"

namespace glfw
{
    class Callbacks
    {
    public:
        Callbacks() = delete;

        static void size_callback(GLFWwindow* handle, int32_t width, int32_t height);
    };
}