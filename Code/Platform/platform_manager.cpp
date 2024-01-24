#include "platform_manager.hpp"

bool PlatformManager::init(const base::PlatformFactory* factory)
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
    _platform->update();
}

PlatformManager& PlatformManager::instance()
{
    static PlatformManager instance;
    return instance;
}
