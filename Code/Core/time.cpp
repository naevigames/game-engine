#include "time.hpp"

void Time::init()
{
    _offset = time_clock::now();
}

void Time::update()
{
    auto current = time_clock::now();

    _delta_time = std::chrono::duration<float,
                  std::chrono::seconds::period>(current - _offset).count();
    _offset = current;
}

float Time::delta_time()
{
    return _delta_time;
}