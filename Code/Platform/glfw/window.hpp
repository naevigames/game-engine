#pragma once

#include "base/window.hpp"

namespace glfw
{
    class Window final : public base::Window
    {
    public:
        bool create()  final;
        void destroy() final;

    private:
        GLFWwindow* _handle;
    };
}