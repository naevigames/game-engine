#pragma once

#include "base/platform_factory.hpp"

using namespace base;

class PlatformManager
{
public:
    void init(PlatformFactory* factory, const window::config& config);
    void update();
    void release();

    bool is_active() const;

private:
    Platform* _platform;
    Window*   _window;
};