#include "platform_manager.hpp"

#ifdef USE_GLFW_PLATFORM
#include "glfw/platform_factory.hpp"
#endif

int32_t PlatformManager::init()
{
    #ifdef USE_GLFW_PLATFORM
    _platform_factory = std::make_unique<glfw::PlatformFactory>();
    #endif
           _platform = _platform_factory->create_platform();
    return _platform->init();
}

void PlatformManager::release()
{
    _platform->release();
}

void PlatformManager::update()
{
    _platform->poll_events();
}

PlatformManager& PlatformManager::instance()
{
    static PlatformManager instance;
    return instance;
}

const base::PlatformFactory* PlatformManager::platform_factory() const
{
    return _platform_factory.get();
}
