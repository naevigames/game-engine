#pragma once

using chrono_clock = std::chrono::high_resolution_clock;
using chrono_time  = std::chrono::high_resolution_clock::time_point;

class Time
{
public:
    void init();
    void update();

    static float delta_time();

private:
    inline static float _delta_time { };
            chrono_time _last_time;
};