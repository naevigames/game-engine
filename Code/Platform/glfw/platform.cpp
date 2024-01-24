#include "platform.hpp"

namespace glfw
{
    bool Platform::init()
    {
        return glfwInit() == GLFW_TRUE;
    }

    void Platform::release()
    {
        glfwTerminate();
    }

    void Platform::update() const
    {
        glfwPollEvents();
    }
}