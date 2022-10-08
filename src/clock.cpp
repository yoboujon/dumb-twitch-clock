#include <iostream>
#include <math.h>
#include <limits.h>
#include "../include/clock.hpp"

/**
 * Constructor of clock, automatic values will be 1h00m00s
 */
Clock::Clock() : m_hour(1), m_minute(0), m_second(0)
{}

/**
 * Constructor of clock, only the hour will be set, the rest will be 0
 * @param hour      Clock's hour
 */
Clock::Clock(int hour) : m_hour(hour), m_minute(0), m_second(0)
{}

/**
 * Constructor of clock, only the hour and minutes will be set, second will be set to 0
 * @param hour      Clock's hour
 * @param minute    Clock's minutes
 */
Clock::Clock(int hour,int minute) : m_hour(hour), m_minute(minute), m_second(0)
{}

/**
 * Constructor of clock
 * @param hour      Clock's hour
 * @param minute    Clock's minutes
 * @param second    Clock's seconds
 */
Clock::Clock(int hour,int minute,int second) : m_hour(hour), m_minute(minute), m_second(second)
{}

/**
 * Prints out the clock in the following format : h:m:s
 */
void Clock::printClock() const
{
    std::cout << m_hour << ":" << m_minute << ":" << m_second << std::endl;
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
            modifyMinutes(-1);
            m_second=60+count;
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