#pragma once

#include "core/platform.hpp"
#include "core/window.hpp"

class PlatformManager
{
public:
    PlatformManager(core::Platform* platform, core::Window* window);

    void init(const window::config& config);
    void update();
    void release();

private:
    core::Platform* _platform;
    core::Window*   _window;
};