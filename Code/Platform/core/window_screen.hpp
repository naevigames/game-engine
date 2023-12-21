#pragma once

class WindowScreen
{
public:
    static int32_t width()  { return _width;  }
    static int32_t height() { return _height; }

private:
    static void resize(int32_t width, int32_t height)
    {
        _width  = width;
        _height = height;
    }

private:
    inline static int32_t _width  = 0;
    inline static int32_t _height = 0;
};