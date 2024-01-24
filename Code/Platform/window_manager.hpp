#pragma once

#include "base/platform_factory.hpp"

class WindowManager
{
public:
    bool init(const base::PlatformFactory* factory);
    void release();
    void update();

private:
    std::unique_ptr<base::Window> _window;

    WindowManager();
};