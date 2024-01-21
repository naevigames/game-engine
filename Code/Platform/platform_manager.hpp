#pragma once

#include "base/platform_factory.hpp"

class PlatformManager
{
public:
    int32_t init();
    void    release();
    void    update();

    static PlatformManager& instance();

    [[nodiscard]] const base::PlatformFactory* platform_factory() const;

private:
    std::unique_ptr<base::PlatformFactory> _platform_factory;
    std::unique_ptr<base::Platform>        _platform;

    PlatformManager() = default;
};
