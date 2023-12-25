#pragma once

#include "core/platform.hpp"

namespace glfw
{
    class Platform final : public core::Platform
    {
    public:
        void init()    final;
        void release() final;

        void poll_events() const final;
    };
}