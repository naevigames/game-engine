#pragma once

#include "platform.hpp"
#include "window.hpp"

namespace base
{
    class PlatformFactory
    {
    public:
        [[nodiscard]] virtual Platform* create_platform() const = 0;
        [[nodiscard]] virtual Window*   create_window()   const = 0;
    };
}