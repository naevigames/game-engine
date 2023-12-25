#pragma once

#include "core/platform_factory.hpp"

namespace glfw
{
    class PlatformFactory final : public core::PlatformFactory
    {
    public:
        [[nodiscard]] core::Platform* create_platform() const final;
        [[nodiscard]] core::Window*   create_window()   const final;
    };
}