#ifndef CLOCK_H
#define CLOCK_H

#include <fstream>

class Clock{
    private:
        std::string m_file;
        int m_hour;
        int m_minute;
        int m_second;

        std::string printClock() const;
        void modifySeconds(int count);
        void modifyMinutes(int count);
        void modifyHours(int count);
        bool hasClockEnded() const;
        void write2File(std::string text) const;
        
    public:
        Clock(std::string file);
        Clock(std::string file, int hour);
        Clock(std::string file, int hour,int minute);
        Clock(std::string file, int hour,int minute,int second);
        void countDown(int count);
};

#endif