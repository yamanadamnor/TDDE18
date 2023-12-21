#include "Battery.hpp"

Battery::Battery(const std::string &&name, double voltage, Connection *positive,
                 Connection *negative)
    : Component(std::move(name), positive, negative), voltage(voltage) {}

void Battery::setCharge() const {
  positive->setCharge(this->voltage);
  negative->setCharge(0);
}

// Idealized battery has no current
double Battery::getCurrent() const { return 0; }

// Set the charge on every simulation step to never run out
void Battery::simulate(double) { setCharge(); }
