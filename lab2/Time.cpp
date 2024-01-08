#include "Time.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Time &increment(Time &time, int inc) {
  int oldTimeInSec{get_time_in_seconds(time)};

  if (oldTimeInSec + inc <= 0) {
    oldTimeInSec = oldTimeInSec + 86400 + (inc % 86400);
  } else {
    oldTimeInSec = oldTimeInSec + inc;
  }

  time.hour = (oldTimeInSec / 3600) % 24;
  time.minute = (oldTimeInSec % 3600) / 60;
  time.second = (oldTimeInSec % 3600) % 60;

  return time;
}

Time operator+(const Time &time, int seconds) {
  Time timeCopy = time;
  return increment(timeCopy, seconds);
}

Time operator-(const Time &time, int seconds) {
  Time timeCopy = time;
  return increment(timeCopy, -seconds);
}

// Prefix operator++
Time &operator++(Time &time) { return increment(time, 1); }

// Postfix operator++
Time operator++(Time &time, int) {
  Time oldTime = time;
  ++time;
  return oldTime;
}

// Prefix operator--
Time &operator--(Time &time) { return increment(time, -1); }

// Postfix operator--
Time operator--(Time &time, int) {
  Time oldTime = time;
  --time;
  return oldTime;
}

bool operator>(const Time &lhs, const Time &rhs) {
  int timeRightInSec = get_time_in_seconds(rhs);
  int timeLeftInSec = get_time_in_seconds(lhs);
  return timeLeftInSec > timeRightInSec;
}

bool operator>=(const Time &lhs, const Time &rhs) {
  return lhs > rhs || lhs == rhs;
}

bool operator<(const Time &lhs, const Time &rhs) {
  int timeRightInSec = get_time_in_seconds(rhs);
  int timeLeftInSec = get_time_in_seconds(lhs);
  return timeLeftInSec < timeRightInSec;
}

bool operator<=(const Time &lhs, const Time &rhs) {
  return lhs < rhs || lhs == rhs;
}

bool operator==(const Time &lhs, const Time &rhs) {
  int timeRightInSec = get_time_in_seconds(rhs);
  int timeLeftInSec = get_time_in_seconds(lhs);
  return timeLeftInSec == timeRightInSec;
}

bool operator!=(const Time &lhs, const Time &rhs) { return !(lhs == rhs); }

ostream &operator<<(ostream &os, const Time &time) {
  os << to_string(time);
  return os;
}

istream &operator>>(istream &is, Time &time) {
  char c;
  int hour;
  int minute;
  int second;

  is >> hour;
  is >> c;
  is >> minute;
  is >> c;
  is >> second;

  time.hour = hour;
  time.minute = minute;
  time.second = second;

  if (!is_valid(time)) {
    is.setstate(std::ios_base::failbit);
  }
  return is;
}

string to_string(const Time &time, bool shortFormat) {
  stringstream ss;
  string ampm;
  Time formattedTime{shortFormat ? format_ampm(time) : time};

  if (shortFormat) {
    ampm = is_am(time) ? " am" : " pm";
  }

  ss << setw(2) << setfill('0') << setw(2) << std::to_string(formattedTime.hour)
     << ":" << setw(2) << std::to_string(formattedTime.minute) << ":" << setw(2)
     << std::to_string(formattedTime.second) << ampm;
  return ss.str();
}

Time format_ampm(const Time &time) {
  Time newTime{time};
  newTime.hour = newTime.hour % 12;

  // Hour 0 should be 12
  newTime.hour = newTime.hour == 0 ? 12 : newTime.hour;

  return newTime;
}

bool is_valid(const Time &time) {
  bool isValidHour = is_valid_hour(time.hour);
  bool isValidMinute = is_valid_minute(time.minute);
  bool isValidSecond = is_valid_second(time.second);

  return (isValidHour && isValidMinute && isValidSecond);
}
bool is_valid_hour(int hour) { return (hour >= 0 && hour <= 23); }

bool is_valid_minute(int minute) { return (minute >= 0 && minute <= 59); }

bool is_valid_second(int second) { return (second >= 0 && second <= 59); }

bool is_am(const Time &time) { return (time.hour >= 0 && time.hour <= 11); }

int get_time_in_seconds(const Time &time) {
  return time.hour * 3600 + time.minute * 60 + time.second;
}
