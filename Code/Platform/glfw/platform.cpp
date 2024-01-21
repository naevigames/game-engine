#include "platform.hpp"

namespace glfw
{
    int32_t Platform::init()
    {
        return glfwInit();
    }

    void Platform::release()
    {
        glfwTerminate();
    }

    void Platform::poll_events() const
    {
        glfwPollEvents();
    }
}