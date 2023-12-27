#pragma once

using chrono_clock = std::chrono::high_resolution_clock;
using chrono_time  = std::chrono::high_resolution_clock::time_point;

class Time
{
public:
    void init();
    void update();

    float delta_time() const;

private:
    chrono_time _last_time;
    float       _delta_time;
};