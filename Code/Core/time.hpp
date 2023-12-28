#pragma once

using time_clock = std::chrono::high_resolution_clock;
using time_point = std::chrono::high_resolution_clock::time_point;

class Time
{
public:
    void init();
    void update();

    static float delta_time();

private:
    inline static float _delta_time { };
             time_point _offset;
};