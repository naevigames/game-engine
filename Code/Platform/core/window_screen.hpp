#pragma once

class WindowScreen
{
public:
    static int32_t width()  { return _width;  }
    static int32_t height() { return _height; }
    static float   ratio()  { return _ratio;  }

    static void resize(int32_t width, int32_t height)
    {
        _width  = width;
        _height = height;

        _ratio  = (float)_width / (float)_height;
    }

private:
    inline static int32_t _width  { };
    inline static int32_t _height { };
    inline static float   _ratio  { };
};