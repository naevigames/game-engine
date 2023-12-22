#include "screen.hpp"

namespace window
{
    void Screen::resize(int32_t width, int32_t height)
    {
        _width  = width;
        _height = height;

        _ratio  = (float)_width / (float)_height;
    }

    int32_t Screen::width()
    {
        return _width;
    }

    int32_t Screen::height()
    {
        return _height;
    }

    float Screen::ratio()
    {
        return _ratio;
    }
}