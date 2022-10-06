#include "value.hpp"
#include "clock.hpp"

int main()
{
    int h,m,s;
    askValues(&h,&m,&s);
    choice(&h,&m,&s);
    Clock mainClock(h,m,s);
    mainClock.printClock();
    return 0;
}