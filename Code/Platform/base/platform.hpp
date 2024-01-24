#pragma once

namespace base
{
    class Platform
    {
    public:
        virtual bool init()         = 0;
        virtual void release()      = 0;
        virtual void update() const = 0;

        virtual ~Platform() = default;
    };
}