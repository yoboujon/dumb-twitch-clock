#include "../include/value.hpp"
#include "../include/clock.hpp"
#include <chrono>
#include <thread>

int main()
{
    int h,m,s;
    askValues(&h,&m,&s);
    choice(&h,&m,&s);
    Clock mainClock(h,m,s);
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        mainClock.modifySeconds(-1);
        mainClock.printClock();
    }
    return 0;
}