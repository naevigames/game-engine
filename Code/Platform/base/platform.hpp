#pragma once

namespace base
{
    class Platform
    {
    public:
        virtual int32_t init() = 0;
        virtual void release() = 0;
        virtual    ~Platform() = default;

        virtual void poll_events() const = 0;
    };
}