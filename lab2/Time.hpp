#ifndef TIME_H
#define TIME_H
#include <string>
#include <iostream>

struct Time
{
  int hour;
  int minute;
  int second;

  Time(int h = 0, int m = 0, int s = 0);

  Time operator+(int incrementor) const;
  Time operator-(int decrementor) const;

  // Prefix operators
  Time &operator++();
  Time &operator--();

  // Postfix operators
  Time operator++(int);
  Time operator--(int);

  // Comparison operators
  bool operator>(const Time &time2) const;
  bool operator<(const Time &time2) const;
  bool operator<=(const Time &time2) const;
  bool operator>=(const Time &time2) const;

  bool operator==(const Time &time2) const;
  bool operator!=(const Time &time2) const;

  std::string to_string(bool shortFormat = false) const;

  Time format_ampm(Time time) const;

  bool is_valid() const;
  bool is_valid_hour() const;
  bool is_valid_minute() const;
  bool is_valid_second() const;
  bool is_am() const;

  int get_time_in_seconds() const;
};

std::istream &operator>>(std::istream &is, Time &time);
std::ostream &operator<<(std::ostream &is, Time &time);

#endif
