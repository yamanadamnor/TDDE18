#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <string>

// TODO: Complementary work needed: The functions should not be member
// functions, as in do not put them in the struct. That does also mean you
// should not create a constructor.

struct Time {
  int hour;
  int minute;
  int second;
};

Time operator+(const Time &time, int incrementor);
Time operator-(const Time &time, int decrementor);

// Prefix operators
Time &operator++(Time &time);
Time &operator--(Time &time);

// Postfix operators
Time operator++(Time &time, int);
Time operator--(Time &time, int);

// Comparison operators
bool operator>(const Time &lhs, const Time &rhs);
bool operator<(const Time &lhs, const Time &rhs);
bool operator<=(const Time &lhs, const Time &rhs);
bool operator>=(const Time &lhs, const Time &rhs);
bool operator!=(const Time &lhs, const Time &rhs);
bool operator==(const Time &lhs, const Time &rhs);

std::istream &operator>>(std::istream &is, Time &time);
std::ostream &operator<<(std::ostream &os, const Time &time);

int get_time_in_seconds(const Time &time);
Time &increment(Time &time, int seconds);
Time format_ampm(const Time &time);
std::string to_string(const Time &time, bool shortFormat = false);

bool is_am(const Time &time);
bool is_valid(const Time &time);
bool is_valid_hour(int hour);
bool is_valid_minute(int minute);
bool is_valid_second(int second);

#endif
