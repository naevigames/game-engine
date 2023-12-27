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
    std::unique_ptr<Platform> _platform;
    std::unique_ptr<Window>   _window;    // TODO add an active bool here and set it true if you close the window in close callback?
};