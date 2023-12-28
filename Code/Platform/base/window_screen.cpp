#include "window_screen.hpp"

void WindowScreen::set_size(const window_size& size)
{
    _width  = size.width;
    _height = size.height;

    _ratio  = static_cast<float>(_width) /
              static_cast<float>(_height);
}

int32_t WindowScreen::width()
{
    return _width;
}

int32_t WindowScreen::height()
{
    return _height;
}

float WindowScreen::ratio()
{
    return _ratio;
}