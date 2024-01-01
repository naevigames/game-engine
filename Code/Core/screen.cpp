#include "screen.hpp"

void Screen::set_size(const size& size)
{
    _width  = size.width;
    _height = size.height;

    _ratio  = static_cast<float>(_width) /
              static_cast<float>(_height);
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