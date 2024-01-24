#include "window_manager.hpp"

WindowManager::WindowManager()
{
}

bool WindowManager::init(const base::PlatformFactory* factory, const base::window_config& config)
{
    _window = factory->create_window();

    _window->hint({ GLFW_RESIZABLE, GLFW_FALSE });

    if (!_window->create(config))
    {
        return false;
    }

    _window->activate();

    return true;
}

void WindowManager::release()
{
}

void WindowManager::update()
{
}

WindowManager& WindowManager::instance()
{
    static WindowManager instance;
    return instance;
}
