#pragma once

#include "base/platform_factory.hpp"

class WindowManager
{
public:
    void init(const base::PlatformFactory* factory, const base::window_config& config);
    void release();
    void update();

    void shutdown();

    [[nodiscard]] bool is_active() const;

    static WindowManager& instance();

private:
    WindowManager();

    std::unique_ptr<base::Context> _context;
    std::unique_ptr<base::Window>  _window;

    bool _active;
};