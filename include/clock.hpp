#ifndef CLOCK_H
#define CLOCK_H

class Clock{
    private:
        int m_hour;
        int m_minute;
        int m_second;
        
    public:
        Clock();
        Clock(int hour);
        Clock(int hour,int minute);
        Clock(int hour,int minute,int second);
        void printClock() const;
        void modifySeconds(int count);
        void modifyMinutes(int count);
        void modifyHours(int count);
};

#endif