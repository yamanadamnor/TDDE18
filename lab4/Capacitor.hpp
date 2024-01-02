#ifndef CAPACITOR_H
#define CAPACITOR_H
#include "Component.hpp"

class Capacitor : public Component {
public:
  Capacitor(const std::string &name, double capacitance, Connection *positive,
            Connection *negative);
  double getCurrent() const;
  void simulate(double time_step);
  void setStoredCharge(double charge);

private:
  double stored_charge;
  double const capacitance;
};

#endif
