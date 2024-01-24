#include "window_manager.hpp"

WindowManager::WindowManager()
{
}

bool WindowManager::init(const base::PlatformFactory* factory)
{
    _window = factory->create_window();

    return true;
}

void WindowManager::release()
{
}

void WindowManager::update()
{
}