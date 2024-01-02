#pragma once

#include "base/context.hpp"

namespace glfw
{
    class Context final : public base::Context
    {
    public:
        void load() const final;
    };
}