#pragma once

#include "base/platform_factory.hpp"

using namespace base;

class PlatformManager
{
public:
    void init(PlatformFactory* factory, const window::config& config);
    void update();
    void release();
    void shutdown();

    static PlatformManager& instance();

    [[nodiscard]] bool is_active() const;

private:
    PlatformManager();

    std::unique_ptr<Platform> _platform;
    std::unique_ptr<Window>   _window;

    bool _is_active;
};