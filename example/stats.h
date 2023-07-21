//
// Created by daiyi on 2019/09/30.
//

#ifndef LEVELDB_STATS_H
#define LEVELDB_STATS_H


#include <cstdint>
#include <map>
#include <vector>
#include <cstring>
#include "timer.h"
#include <chrono>

using std::string;
using std::to_string;
using namespace std::chrono;

namespace adgMod {

    class Timer;
    class Stats {
    private:
        static Stats* singleton;
        Stats();

        std::vector<Timer> timers;
    public:
        system_clock::time_point initial_time;

        static Stats* GetInstance();
        void StartTimer(uint32_t id);
        std::pair<uint64_t, uint64_t> PauseTimer(uint32_t id, bool record = false);
        void ResetTimer(uint32_t id);
        uint64_t ReportTime(uint32_t id);
        void ReportTime();

        void ResetAll();
        ~Stats();
    };


}


#endif //LEVELDB_STATS_H
