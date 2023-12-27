#include "core_manager.hpp"

void CoreManager::init()
{
    _time = std::make_unique<Time>();
    _time->init();
}

void CoreManager::update()
{
    _time->update();
}

void CoreManager::release()
{
}
