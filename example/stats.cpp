//
// Created by daiyi on 2019/09/30.
//

#include <cassert>
#include "stats.h"
#include <cmath>
#include <iostream>
#include <x86intrin.h>

using std::stoull;

namespace adgMod {

    Stats* Stats::singleton = nullptr;

    Stats::Stats() : timers(20, Timer{}), initial_time(system_clock::now()) {
        timers[0].setName("FindFiles");
        timers[1].setName("LoadIB+FB");
        timers[2].setName("SearchIB+SearchDB");
        timers[3].setName("SearchFB");
        timers[4].setName("LoadDB");
        timers[5].setName("ReadValue");
    }

    Stats* Stats::GetInstance() {
        if (!singleton) singleton = new Stats();
        return singleton;
    }

    void Stats::StartTimer(uint32_t id) {
        Timer& timer = timers[id];
        timer.Start();
    }

    std::pair<uint64_t, uint64_t> Stats::PauseTimer(uint32_t id, bool record) {
        Timer& timer = timers[id];
        return timer.Pause(record);
    }

    void Stats::ResetTimer(uint32_t id) {
        Timer& timer = timers[id];
        timer.Reset();
    }

    uint64_t Stats::ReportTime(uint32_t id) {
        Timer& timer = timers[id];
        return timer.Time();
    }

    void Stats::ReportTime() {
        for (int i = 0; i < timers.size(); ++i) {
            printf("Timer %u: %lu\n", i, timers[i].Time());
        }
    }

    void Stats::ResetAll() {
        for (Timer& t: timers) t.Reset();
        initial_time = system_clock::now();
    }

    Stats::~Stats() {
        ReportTime();
    }

}

































