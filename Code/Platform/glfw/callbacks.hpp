#pragma once

#include "window/screen.hpp"

namespace glfw
{
    class Callbacks
    {
    public:
        Callbacks() = delete;

        static void size_callback(GLFWwindow*, int32_t width, int32_t height);
        static void close_callback(GLFWwindow*);
    };
}