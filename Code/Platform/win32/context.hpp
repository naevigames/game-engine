#pragma once

#include "base/context.hpp"

namespace win32
{
    class Context final : public base::Context
    {
    public:
        void load() const final;
    };
}