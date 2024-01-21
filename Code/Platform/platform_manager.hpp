#pragma once

#include "base/platform_factory.hpp"

class PlatformManager
{
public:
    int32_t init(base::PlatformFactory* factory);
    void    release();
    void    update();

    static PlatformManager& instance();

private:
    PlatformManager() = default;

    std::unique_ptr<base::Platform> _platform;
};
