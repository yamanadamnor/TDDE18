#include <string>

#include "Capacitor.hpp"

Capacitor::Capacitor(std::string &&name, double capacitance,
                     double stored_charge, Connection *positive,
                     Connection *negative)
    : Component(std::move(name), positive, negative), capacitance(capacitance),
      stored_charge(stored_charge) {}

double Capacitor::getCurrent() const {
  return capacitance * (this->getVoltage() - stored_charge);
}

void Capacitor::setStoredCharge(double charge) { this->stored_charge = charge; }

void Capacitor::simulate(double time_step) {
  double positiveCharge = positive->getCharge();
  double negativeCharge = negative->getCharge();
  double potential_difference{this->getVoltage()};
  double chargeToStore{capacitance * (potential_difference - stored_charge) * time_step};
  this->setStoredCharge(stored_charge + chargeToStore);

  if (positiveCharge > negativeCharge) {
    positive->setCharge(positiveCharge - chargeToStore);
    negative->setCharge(negativeCharge + chargeToStore);
  } else {
    positive->setCharge(positiveCharge + chargeToStore);
    negative->setCharge(negativeCharge - chargeToStore);
  }
}
