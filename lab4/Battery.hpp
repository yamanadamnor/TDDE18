#ifndef BATTERY_H
#define BATTERY_H
#include <string>
#include "Component.hpp"

class Battery : public Component {
private:
  double voltage;
public:

  // Constructor
  Battery(const std::string &&name, double voltage, Connection *positive, Connection *negative);
  double getCurrent() const;
  void simulate(double time_step);
  void setCharge(double voltage);
};

#endif
