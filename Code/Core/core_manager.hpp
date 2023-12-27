#pragma once

#include "time.hpp"

class CoreManager
{
public:
    void init();
    void update();
    void release();

private:
    std::unique_ptr<Time> _time;
};