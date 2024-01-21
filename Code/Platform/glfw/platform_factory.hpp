#pragma once

#include "base/platform_factory.hpp"

namespace glfw
{
    class PlatformFactory final : public base::PlatformFactory
    {
    public:
        [[nodiscard]] std::unique_ptr<base::Platform> create_platform() const final;
    };
}