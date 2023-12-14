#include "Component.hpp"

#include <string>

Component::Component(const std::string &&name, Connection *negative, Connection *positive)
    : name(name), negative(negative), positive(positive) {}

double Component::getVoltage() const {
  return std::abs(positive->getCharge() - negative->getCharge());
}

const std::string &Component::getName() const { return name; }
