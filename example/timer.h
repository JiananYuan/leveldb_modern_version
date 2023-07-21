//
// Created by daiyi on 2020/02/02.
//

#ifndef LEVELDB_TIMER_H
#define LEVELDB_TIMER_H


#include <cstdint>
#include <ctime>
#include <utility>
#include <vector>
#include <chrono>
#include <string>
using namespace std::chrono;

namespace adgMod {

    class Timer {
        system_clock::time_point time_started;
        uint64_t time_accumulated;
        bool started;
        std::string name;

    public:
        void Start();
        std::pair<uint64_t, uint64_t> Pause(bool record = false);
        void Reset();
        uint64_t Time();
        void setName(std::string);
        std::string Name();

        Timer();
        ~Timer() = default;
    };

}


#endif //LEVELDB_TIMER_H
