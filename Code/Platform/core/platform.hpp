#pragma once

namespace core
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