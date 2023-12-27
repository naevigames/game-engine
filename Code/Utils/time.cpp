#include "time.hpp"

void Time::init()
{
    _last_time = chrono_clock::now();
}

void Time::update()
{
    auto current = chrono_clock::now();

    _delta_time = std::chrono::duration<float,
                  std::chrono::seconds::period>(current - _last_time).count();
    _last_time  = current;
}


float Time::delta_time() const
{
    return _delta_time;
}