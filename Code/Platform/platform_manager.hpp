#pragma once

#include "base/platform.hpp"
#include "base/window.hpp"

using namespace base;

class PlatformManager
{
public:
    PlatformManager(Platform* platform, Window* window);

    void init(const window::config& config);
    void update();
    void release();

private:
    Platform* _platform;
    Window*   _window;
};