#include "platform_manager.hpp"

void PlatformManager::init(PlatformFactory* factory, const window::config& config)
{
    _platform = factory->create_platform();
    _platform->init();

    _window = factory->create_window();
    _window->hint({ GLFW_CONTEXT_VERSION_MAJOR, 3 });
    _window->hint({ GLFW_CONTEXT_VERSION_MINOR, 3 });
    _window->hint({ GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE });
    _window->hint({ GLFW_SAMPLES, 4 });

    _window->create(config);
    _window->activate();

    _window->register_user_pointer();
    _window->register_size_callback();

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSwapInterval(1);
}

void PlatformManager::update()
{
    _window->swap_buffers();

    _platform->poll_events();
}

void PlatformManager::release()
{
    _window->destroy();

    _platform->release();
}

bool PlatformManager::is_active() const
{
    return !_window->is_closed();
}
