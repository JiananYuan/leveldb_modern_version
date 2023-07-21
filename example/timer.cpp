//
// Created by daiyi on 2020/02/02.
//

#include "timer.h"
#include <cassert>
#include <string>
using namespace std::chrono;


namespace adgMod {

    Timer::Timer() : time_accumulated(0), started(false) {}

    void Timer::Start() {
        assert(!started);
        time_started = system_clock::now();
        started = true;
    }

    std::pair<uint64_t, uint64_t> Timer::Pause(bool record) {
        assert(started);
        auto time_elapse = duration<double, std::nano>(system_clock::now() - time_started).count();
        time_accumulated += time_elapse;

        if (record) {
            // Stats* instance = Stats::GetInstance();
            // uint64_t start_absolute = time_started - instance->initial_time;
            // uint64_t end_absolute = start_absolute + time_elapse;
            // started = false;
            // return {start_absolute / reference_frequency, end_absolute / reference_frequency};
        } else {
            started = false;
            return {0, 0};
        }
        return {0, 0};
    }

    void Timer::Reset() {
        time_accumulated = 0;
        started = false;
    }

    uint64_t Timer::Time() {
        //assert(!started);
        return time_accumulated;
    }

    void Timer::setName(std::string _name) {
        name = _name;
    }

    std::string Timer::Name() {
        return name;
    }
}