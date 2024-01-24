#include "context.hpp"

namespace glfw
{
    void Context::load() const
    {
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    }
}