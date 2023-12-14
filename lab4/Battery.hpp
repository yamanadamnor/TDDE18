#ifndef BATTERY_H
#define BATTERY_H
#include "Component.hpp"

class Battery : Component {
public:
  double voltage{};

  Battery();
};

#endif
