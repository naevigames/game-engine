#pragma once

#include "window_size.hpp"

class WindowScreen // TODO this will be removed when we have events?
{
public:
    WindowScreen() = delete;

    static int32_t width();
    static int32_t height();
    static float   ratio();

    static void set_size(const window_size& size);

private:
    inline static int32_t _width  { };
    inline static int32_t _height { };
    inline static float   _ratio  { }; // TODO remove this in the future
};