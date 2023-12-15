#include <string>

#include "Capacitor.hpp"

Capacitor::Capacitor(std::string &&name, double capacitance,
                     Connection *positive, Connection *negative)
    : Component(std::move(name), positive, negative), capacitance(capacitance) {
}

double Capacitor::getCurrent() const {
  return (getVoltage() - stored_charge) * capacitance;
}

void Capacitor::setStoredCharge(double charge) { stored_charge = charge; }

void Capacitor::simulate(double time_step) {
  double positiveCharge = positive->getCharge();
  double negativeCharge = negative->getCharge();
  double potential_difference{getVoltage()};
  double chargeToStore{capacitance * (potential_difference - stored_charge) *
                       time_step};

  setStoredCharge(stored_charge + chargeToStore);

  if (positiveCharge > negativeCharge) {
    positive->setCharge(positiveCharge - chargeToStore);
    negative->setCharge(negativeCharge + chargeToStore);
  } else {
    positive->setCharge(positiveCharge + chargeToStore);
    negative->setCharge(negativeCharge - chargeToStore);
  }
}
