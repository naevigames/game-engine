#pragma once

#include "base/platform_factory.hpp"

namespace glfw
{
    class PlatformFactory final : public base::PlatformFactory
    {
    public:
        [[nodiscard]] std::unique_ptr<base::Platform> create_platform() const final;
        [[nodiscard]] std::unique_ptr<base::Context>  create_context()  const final;
        [[nodiscard]] std::unique_ptr<base::Window>   create_window()   const final;
    };
}