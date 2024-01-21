#pragma once

#include "platform.hpp"

namespace base
{
    class PlatformFactory
    {
    public:
        [[nodiscard]] virtual std::unique_ptr<Platform> create_platform() const = 0;
    };
}