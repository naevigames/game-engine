#pragma once

#include "base/platform.hpp"

namespace win32
{
    class Platform final : public base::Platform
    {
    public:
        void init()    final;
        void release() final;

        void poll_events() const final;
    };
}