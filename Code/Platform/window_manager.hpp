#pragma once

#include "base/platform_factory.hpp"

class WindowManager
{
public:
    bool init(const base::PlatformFactory* factory, const base::window_config& config);
    void release();
    void update();

    static WindowManager& instance();

private:
    std::unique_ptr<base::Window> _window;

    WindowManager();
};