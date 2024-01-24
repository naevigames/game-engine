#pragma once

namespace base
{
    class Window
    {
    public:
        virtual bool create()  = 0;
        virtual void destroy() = 0;

        virtual ~Window() = default;
    };
}