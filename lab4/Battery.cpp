#include "Battery.hpp"

Battery::Battery(const std::string &&name, double voltage, Connection *positive, Connection *negative)
    : Component(std::move(name), positive, negative), voltage(voltage) {
  this->setCharge(this->voltage);
};

void Battery::setCharge(double voltage) {
  positive->setCharge(this->voltage);
  negative->setCharge(0);
}

double Battery::getCurrent() const {
  // Idealized battery has no current
  return 0;
};

// Set the charge on every simulation step to never run out
void Battery::simulate(double time_step) {
  this->setCharge(this->voltage);
}
