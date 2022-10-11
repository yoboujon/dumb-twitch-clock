#include <iostream>
#include <math.h>
#include <limits.h>
#include <chrono>
#include <thread>
#include <string> 
#include "../include/clock.hpp"

/**
 * Constructor of clock, automatic values will be 1h00m00s
 * @param file      Output filename for the clock
 */
Clock::Clock(std::string file) : m_file(file), m_hour(1), m_minute(0), m_second(0)
{}

/**
 * Constructor of clock, only the hour will be set, the rest will be 0
 * @param file      Output filename for the clock
 * @param hour      Clock's hour
 */
Clock::Clock(std::string file, int hour) : m_file(file), m_hour(hour), m_minute(0), m_second(0)
{}

/**
 * Constructor of clock, only the hour and minutes will be set, second will be set to 0
 * @param file      Output filename for the clock
 * @param hour      Clock's hour
 * @param minute    Clock's minutes
 */
Clock::Clock(std::string file, int hour,int minute) : m_file(file), m_hour(hour), m_minute(minute), m_second(0)
{}

/**
 * Constructor of clock
 * @param file      Output filename for the clock
 * @param hour      Clock's hour
 * @param minute    Clock's minutes
 * @param second    Clock's seconds
 */
Clock::Clock(std::string file, int hour,int minute,int second) : m_file(file), m_hour(hour), m_minute(minute), m_second(second)
{}

/**
 * Destructor of Clock
*/
Clock::~Clock(){};

/**
 * Prints out the clock in the following format : h:m:s
 * Next time it will be configurable
 */
std::string Clock::printClock() const
{
    std::string hourString=std::to_string(m_hour)+':',minuteString=std::to_string(m_minute)+':',secondString=std::to_string(m_second);
    if(m_hour < 10)
    {
        hourString = '0' + hourString;
    }
    if(m_minute < 10)
    {
        minuteString = '0' + minuteString;
    }
    if(m_second < 10)
    {
        secondString = '0' + secondString;
    }
    return (hourString + minuteString + secondString);
}

void Clock::modifySeconds(int count)
{
    if(count >= 60)
    {
        modifyMinutes(1);
        modifySeconds(count-60);
    }
    else if(count <= -60)
    {
        modifyMinutes(-1);
        modifySeconds(count+60);
    }
    else{
        m_second=m_second+count;
        if(m_second > 59)       //on ajoute du temps (donc positif)
        {
            modifyMinutes(1);
            m_second=m_second-60;
        }
        if(m_second < 0)        //on supprime du temps (donc négatif)
        {
            if(m_hour == 0 && m_minute == 0)
            {
                m_second = 0;
            }
            else
            {
                m_second=60+count;
                modifyMinutes(-1);
            }
        }
    }
}

void Clock::modifyMinutes(int count)
{
    if(count >= 60)
    {
        modifyHours(1);
        modifyMinutes(count-60);
    }
    else if(count <= -60)
    {
        modifyHours(-1);
        modifyMinutes(count+60);
    }
    else{
        m_minute=m_minute+count;
        if(m_minute > 59)       //on ajoute du temps (donc positif)
        {
            modifyHours(1);
            m_minute=m_second-60;
        }
        if(m_minute < 0)        //on supprime du temps (donc négatif)
        {
            modifyHours(-1);
            m_minute=60+count;
        }
    }
}

void Clock::modifyHours(int count)
{
    m_hour=m_hour+count;
    if(m_hour > pow(2,(sizeof(int)*CHAR_BIT)-1)-1)
    {
        m_hour=0;
    }
    if(m_hour<0)
    {
        m_hour = 0;
        m_second = m_hour;
        m_minute = m_hour;
    }
}

bool Clock::hasClockEnded() const
{
    return (m_hour == 0 && m_minute == 0 && m_second == 0);
}

void Clock::countDown(int count)
{
    std::string clockText;
    while(!hasClockEnded())
    {
        clockText = printClock();
        std::cout << clockText << std::endl;
        write2File(clockText);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        modifySeconds(-count);
    }
    clockText = printClock();
    write2File(clockText);
    std::cout << clockText << std::endl;
}

void Clock::write2File(std::string text) const
{
    std::ofstream fout(m_file);
    fout << text;
    fout.close();
}

void Clock::setClockTime(int h,int m,int s){
    m_hour = h;
    m_minute = m;
    m_second = s;
}