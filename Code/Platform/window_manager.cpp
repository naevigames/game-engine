#include "window_manager.hpp"

WindowManager::WindowManager()
    : _active { }
{
}

void WindowManager::init(const base::PlatformFactory* factory, const base::window_config& config)
{
    _window = factory->create_window();

    _window->hint({ GLFW_RESIZABLE, GLFW_FALSE });

    _active = _window->create(config);

    _window->register_user_pointer();
    _window->register_size_callback();
    _window->register_close_callback();

    _window->activate();
}

void WindowManager::release()
{
    _window->destroy();
}

void WindowManager::update()
{
    _window->swap_buffers();
}

void WindowManager::shutdown()
{
    _active = false;
}

WindowManager& WindowManager::instance()
{
    static WindowManager instance;
    return instance;
}

bool WindowManager::is_active() const
{
    return _active;
}
