#include "platform_manager.hpp"

PlatformManager::PlatformManager()
    : _is_active { }
{
}

void PlatformManager::init(base::PlatformFactory* factory, const base::window_config& config)
{
    _platform = factory->create_platform();
    _window   = factory->create_window();

    _platform->init();

    _window->hint({ GLFW_CONTEXT_VERSION_MAJOR, 4 });
    _window->hint({ GLFW_CONTEXT_VERSION_MINOR, 1 });
    _window->hint({ GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE });
    _window->hint({ GLFW_SAMPLES, 4 });

    _window->create(config);
    _window->activate();

    _window->register_user_pointer();
    _window->register_size_callback();
    _window->register_close_callback();

    _is_active = true;

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSwapInterval(1);
}

void PlatformManager::update()
{
     assert(_is_active);

    _window->swap_buffers();
    _platform->poll_events();
}

void PlatformManager::release()
{
     assert(!_is_active);

    _window->destroy();
    _platform->release();
}

void PlatformManager::shutdown()
{
    _is_active = false;
}

bool PlatformManager::is_active() const
{
    return _is_active;
}

PlatformManager& PlatformManager::instance()
{
    static PlatformManager instance;
    return instance;
}
