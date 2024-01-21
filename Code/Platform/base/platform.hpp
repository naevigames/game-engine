#pragma once

namespace base
{
    class Platform
    {
    public:
        virtual    ~Platform() = default;
        virtual int32_t init() = 0;
        virtual void release() = 0;

        virtual void poll_events() const = 0;
    };
}