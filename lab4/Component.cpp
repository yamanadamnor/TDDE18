#include "Component.hpp"

#include <string>

Component::Component(const std::string &&name, Connection *positive,
                     Connection *negative)
    : name(name), positive(positive), negative(negative) {}

double Component::getVoltage() const {
  return std::abs(positive->getCharge() - negative->getCharge());
}

const std::string &Component::getName() const { return name; }

double Component::getCurrent() const {
  return 0;
}
