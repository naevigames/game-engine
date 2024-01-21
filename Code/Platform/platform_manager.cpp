#include "platform_manager.hpp"

int32_t PlatformManager::init(base::PlatformFactory* factory)
{
           _platform = factory->create_platform();
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
