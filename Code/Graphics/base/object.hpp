#pragma once

namespace base
{
    template <typename type>
    class Object
    {
    protected:
        Object() : _handle { }
        {
        }
        type       _handle;
    };
}