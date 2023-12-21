#include "platform.hpp"

namespace glfw
{
    void Platform::init()
    {
        if (glfwInit() == GLFW_FALSE)
        {
            exit(EXIT_FAILURE);
        }
    }

    void Platform::release()
    {
        glfwTerminate();
    }

    void Platform::poll_events()
    {
        glfwPollEvents();
    }
}