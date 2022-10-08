#include "../include/value.hpp"
#include "../include/clock.hpp"

int main()
{
    int h,m,s;
    askValues(&h,&m,&s);
    choice(&h,&m,&s);
    std::string fileName = "dtc.txt";     //In the future the name could be modified
    Clock mainClock(fileName,h,m,s);
    mainClock.countDown(1);
    return 0;
}