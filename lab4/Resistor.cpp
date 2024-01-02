#include "Resistor.hpp"

Resistor::Resistor(const std::string &name, double resistance, Connection *positive, Connection *negative)
    : Component(name, positive, negative), resistance(resistance) {}

double Resistor::getCurrent() const {
  return (getVoltage() / resistance);
}

void Resistor::simulate(double time_step) {
  double positive_charge = positive->getCharge();
  double negative_charge = negative->getCharge();
  double potential_difference{getVoltage()};
  double chargeToMove{(potential_difference * time_step / resistance)};

  // Positive terminal is highest charged terminal
  if (positive_charge > negative_charge) {
    positive->setCharge(positive_charge - chargeToMove);
    negative->setCharge(negative_charge + chargeToMove);

    // Negative terminal is highest charged terminal
  } else {
    positive->setCharge(positive_charge + chargeToMove);
    negative->setCharge(negative_charge - chargeToMove);
  }
}
