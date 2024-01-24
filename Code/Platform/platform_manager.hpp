#pragma once

#include "base/platform_factory.hpp"

class PlatformManager
{
public:
    bool init(const base::PlatformFactory* factory);
    void release();
    void update();

    static PlatformManager& instance();

private:
    std::unique_ptr<base::Platform> _platform;

    PlatformManager() = default;
};
