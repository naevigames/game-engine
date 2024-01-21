#pragma once

#include "base/platform.hpp"

namespace glfw
{
    class Platform final : public base::Platform
    {
    public:
        int32_t init() final;
        void release() final;

        void poll_events() const final;
    };
}