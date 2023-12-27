#include "platform_manager.hpp"

PlatformManager::PlatformManager(Platform* platform, Window* window)
    : _platform { platform }
    , _window   { window }
{
}

void PlatformManager::init(const window::config& config)
{
    _platform->init();

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
     delete _window;

    _platform->release();
     delete _platform;
}