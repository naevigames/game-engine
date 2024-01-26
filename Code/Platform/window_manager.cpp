#include "window_manager.hpp"

void WindowManager::init(const base::PlatformFactory* factory, const base::window_config& config)
{
    _context = factory->create_context();
    _window  = factory->create_window();

    if (config.vulkan_api)
    {
        _window->hint({ GLFW_CLIENT_API, GLFW_NO_API });
    }

    _window->hint({ GLFW_RESIZABLE, GLFW_FALSE });

    _active = _window->create(config);

    _window->register_user_pointer();
    _window->register_size_callback();
    _window->register_close_callback();

    _window->activate();

    _context->load();
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

std::any WindowManager::handle() const
{
    #ifdef GLFW_PLATFORM
    auto   handle = std::any_cast<GLFWwindow*>(_window->handle());
    return glfwGetWin32Window(handle);
    #endif
}