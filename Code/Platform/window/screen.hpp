#pragma once

namespace window
{
    class Screen
    {
    public:
        Screen() = delete;

        static int32_t width();
        static int32_t height();
        static float   ratio();

        static void    set_size(int32_t width, int32_t height);

    private:
        inline static int32_t _width  { };
        inline static int32_t _height { };
        inline static float   _ratio  { }; // TODO remove this in the future
    };
}