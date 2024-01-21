#include "platform_factory.hpp"
#include "platform.hpp"

namespace glfw
{
    std::unique_ptr<base::Platform> PlatformFactory::create_platform() const
    {
        return std::make_unique<Platform>();
    }
}