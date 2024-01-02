#pragma once

namespace base
{
    class Context
    {
    public:
        virtual ~Context() = default;

        virtual void load()  const
        {
        };
    };
}