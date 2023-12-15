#include "Resistor.hpp"

Resistor::Resistor(const std::string &&name, double resistance,
                   Connection *positive, Connection *negative)
    : Component(std::move(name), positive, negative), resistance(resistance) {}

double Resistor::getCurrent() const {
  return (getVoltage() / resistance);
}

void Resistor::simulate(double time_step) {
  double positiveCharge = positive->getCharge();
  double negativeCharge = negative->getCharge();
  double potential_difference{getVoltage()};
  double chargeToMove{(potential_difference / resistance) * time_step};

  // Positive terminal is highest charged terminal
  if (positiveCharge > negativeCharge) {
    positive->setCharge(positiveCharge - chargeToMove);
    negative->setCharge(negativeCharge + chargeToMove);

    // Negative terminal is highest charged terminal
  } else {
    positive->setCharge(positiveCharge + chargeToMove);
    negative->setCharge(negativeCharge - chargeToMove);
  }
}
