#ifndef CPPU_SLEEP
#define CPPU_SLEEP



#include <chrono>
#include <thread>



void sleep(float seconds) {
    std::chrono::milliseconds ms{static_cast<long int>(seconds * 1000)};
    std::this_thread::sleep_for(ms);
}



#endif