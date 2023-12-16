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
  double positive_charge = positive->getCharge();
  double negative_charge = negative->getCharge();
  double potential_difference{getVoltage()};
  double chargeToStore{capacitance * time_step * (potential_difference - stored_charge)};


  if (positive_charge > negative_charge) {
    positive->setCharge(positive_charge - chargeToStore);
    negative->setCharge(negative_charge + chargeToStore);
  } else {
    positive->setCharge(positive_charge + chargeToStore);
    negative->setCharge(negative_charge - chargeToStore);
  }
  setStoredCharge(stored_charge + chargeToStore);
}
