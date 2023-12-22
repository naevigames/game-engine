#pragma once

namespace window
{
class Screen
{
    public:
        static int32_t width();
        static int32_t height();
        static float   ratio();

        static void    resize(int32_t width, int32_t height);

    private:
        inline static int32_t _width  { };
        inline static int32_t _height { };
        inline static float   _ratio  { };
    };
}