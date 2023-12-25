#include "platform_factory.hpp"
#include "platform.hpp"
#include "window.hpp"

namespace glfw
{
    core::Platform* PlatformFactory::create_platform() const
    {
        return new Platform;
    }

    core::Window* PlatformFactory::create_window() const
    {
        return new Window;
    }
}