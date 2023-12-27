#include "platform_factory.hpp"
#include "platform.hpp"
#include "window.hpp"

namespace glfw
{
    base::Platform* PlatformFactory::create_platform() const
    {
        return new Platform;
    }

    base::Window* PlatformFactory::create_window() const
    {
        return new Window;
    }
}