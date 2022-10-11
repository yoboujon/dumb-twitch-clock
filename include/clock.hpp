#ifndef CLOCK_H
#define CLOCK_H

#include <fstream>

class Clock{
    private:
        std::string m_file;
        int m_hour;
        int m_minute;
        int m_second;

        void modifyMinutes(int count);
        void modifyHours(int count);
        void write2File(std::string text) const;
        
    public:
        Clock(std::string file);
        ~Clock();
        Clock(std::string file, int hour);
        Clock(std::string file, int hour,int minute);
        Clock(std::string file, int hour,int minute,int second);
        std::string printClock() const;
        void setClockTime(int h,int m,int s);
        void countDown(int count);
        void modifySeconds(int count);
        bool hasClockEnded() const;
};

#endif