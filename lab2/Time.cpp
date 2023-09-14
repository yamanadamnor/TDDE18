#include <memory>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Time.hpp"
using namespace std;

Time::Time(int h, int m, int s) : hour(h), minute(m), second(s)
{
    hour = h;
    if (!this->is_valid_hour())
    {
        throw std::invalid_argument("Cannot initialize object. Hour must be between 0-23");
    }

    minute = m;
    if (!this->is_valid_minute())
    {
        throw std::invalid_argument("Cannot initialize object. Minute must be between 0-59");
    }

    minute = m;
    if (!this->is_valid_second())
    {
        throw std::invalid_argument("Cannot initialize object. Second must be between 0-59");
    }
}

// TODO: Validate the Time struct in the constructor
Time &increment(Time &time, int inc)
{
    int oldTimeInSec = time.get_time_in_seconds();
    oldTimeInSec += inc;
    time.hour = oldTimeInSec / 3600;
    time.minute = (oldTimeInSec % 3600) / 60;
    time.second = (oldTimeInSec % 3600) % 60;
    return time;
}

Time Time::operator+(int seconds) const
{
    Time timeCopy = *this;
    return increment(timeCopy, seconds);
}

Time Time::operator-(int seconds) const
{
    Time timeCopy = *this;
    return increment(timeCopy, -seconds);
}

// Prefix operator++
Time &Time::operator++()
{
    return increment(*this, 1);
}

// Postfix operator++
Time Time::operator++(int)
{
    Time oldTime = *this;
    ++*this;
    return oldTime;
}

// Prefix operator--
Time &Time::operator--()
{
    return increment(*this, -1);
}

// Postfix operator--
Time Time::operator--(int)
{
    Time oldTime = *this;
    --*this;
    return oldTime;
}

bool Time::operator>(const Time &time2) const
{
    const Time &oldTime = *this;
    int oldTimeInSec = oldTime.get_time_in_seconds();
    int newTimeInSec = time2.get_time_in_seconds();
    return oldTimeInSec > newTimeInSec;
}

bool Time::operator>=(const Time &time2) const
{
    return *this > time2 || *this == time2;
}

bool Time::operator<(const Time &time2) const
{
    const Time &oldTime = *this;
    int oldTimeInSec = oldTime.get_time_in_seconds();
    int newTimeInSec = time2.get_time_in_seconds();
    return oldTimeInSec < newTimeInSec;
}

bool Time::operator<=(const Time &time2) const
{
    return *this < time2 || *this == time2;
}

bool Time::operator==(const Time &time2) const
{
    const Time &oldTime = *this;
    int oldTimeInSec = oldTime.get_time_in_seconds();
    int newTimeInSec = time2.get_time_in_seconds();
    return oldTimeInSec == newTimeInSec;
}

bool Time::operator!=(const Time &time2) const
{
    return !(*this == time2);
}

ostream &Time::operator<<(ostream &os)
{
    string timeStr = to_string();
    os << timeStr;
    return os;
}

istream &Time::operator>>(istream &is)
{
    int hour;
    int minute;
    int second;

    try
    {
        is >> hour;
        is.ignore(1000, ':');
        is >> minute;
        is.ignore(1000, ':');
        is >> second;

        Time newTime{hour, minute, second};
    }
    catch (const std::exception &e)
    {
        is.setstate(std::ios::failbit);
        std::cerr << e.what() << '\n';
    }
    return is;
}

string Time::to_string(bool shortFormat) const
{
    stringstream ss;
    string ampm;
    Time formattedTime{shortFormat ? format_ampm(*this) : *this};

    if (shortFormat)
    {
        ampm = is_am() ? " am" : " pm";
    }

    ss << setw(2) << setfill('0')
       << setw(2) << std::to_string(formattedTime.hour) << ":"
       << setw(2) << std::to_string(formattedTime.minute) << ":"
       << setw(2) << std::to_string(formattedTime.second)
       << ampm;
    return ss.str();
}

Time Time::format_ampm(Time time) const
{
    time.hour = time.hour % 12;

    // Hour 0 should be 12
    time.hour = time.hour == 0 ? 12 : time.hour;

    return time;
}

bool Time::is_valid() const
{
    bool validHour = this->is_valid_hour();
    bool validMinute = this->is_valid_minute();
    bool validSecond = this->is_valid_second();

    return (validHour && validMinute && validSecond);
}
bool Time::is_valid_hour() const
{
    return (hour >= 0 && hour <= 23);
}

bool Time::is_valid_minute() const
{
    return (minute >= 0 && minute <= 59);
}

bool Time::is_valid_second() const
{
    return (second >= 0 && second <= 59);
}

bool Time::is_am() const
{
    return (hour >= 0 && hour <= 11);
}

int Time::get_time_in_seconds() const
{
    return hour * 3600 + minute * 60 + second;
}