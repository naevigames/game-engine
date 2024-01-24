#pragma once

#include "base/platform.hpp"

namespace glfw
{
    class Platform final : public base::Platform
    {
    public:
        bool init()         final;
        void release()      final;
        void update() const final;
    };
}