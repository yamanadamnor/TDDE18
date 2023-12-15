#ifndef RESISTOR_H
#define RESISTOR_H
#include <string>

#include "Connection.hpp"
#include "Component.hpp"

class Resistor : public Component {
private:
  double resistance;

public:
  Resistor(const std::string &&name, double resistance, Connection *positive,
           Connection *negative);
  double getCurrent() const;
  double getVoltage() const;
  void simulate(double time_step);
};
#endif
