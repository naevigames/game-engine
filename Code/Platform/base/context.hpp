#pragma once

namespace base
{
    class Context
    {
    public:
        virtual void load() const
        {
        }

        virtual ~Context() = default;
    };
}