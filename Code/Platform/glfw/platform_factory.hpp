#pragma once

#include "base/platform_factory.hpp"

namespace glfw
{
    class PlatformFactory final : public base::PlatformFactory
    {
    public:
        [[nodiscard]] base::Platform* create_platform() const final;
        [[nodiscard]] base::Window*   create_window()   const final;
    };
}