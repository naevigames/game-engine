#pragma once

template <typename type>
class Object
{
public:
    type handle() const
    {
        return _handle;
    } // TODO remove this after Program class

protected:
    Object() : _handle { }
    {
    }
    type       _handle;
};