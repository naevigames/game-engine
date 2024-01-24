#include "commands.hpp"

namespace gl
{
    void Commands::clear_color(float r, float g, float b)
    {
        glClearColor(r, g, b, 1.0f);
    }

    void Commands::clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
}