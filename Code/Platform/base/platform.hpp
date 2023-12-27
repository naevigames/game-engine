#pragma once

namespace base
{
    class Platform
    {
    public:
        virtual ~Platform() = default;

        virtual void init()    = 0;
        virtual void release() = 0;

        virtual void poll_events() const = 0;
    };
}