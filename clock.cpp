#include <iostream>
#include "clock.hpp"

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