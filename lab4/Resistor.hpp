#ifndef RESISTOR_H
#define RESISTOR_H
#include <string>

#include "Component.hpp"
#include "Connection.hpp"

class Resistor : public Component {
public:
  Resistor(const std::string &name, double resistance, Connection *positive,
           Connection *negative);
  double getCurrent() const;
  void simulate(double time_step);

private:
  double resistance;
};
#endif
