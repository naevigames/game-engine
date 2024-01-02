#pragma once

#include "base/platform_factory.hpp"

class PlatformManager
{
public:
    void init(base::PlatformFactory* factory, const base::window_config& config);

    void update();
    void release();
    void shutdown();

    [[nodiscard]] bool is_active() const;

    static PlatformManager& instance();

private:
    PlatformManager();

    std::unique_ptr<base::Platform> _platform;
    std::unique_ptr<base::Context>  _context;
    std::unique_ptr<base::Window>   _window;

    bool _is_active;
};