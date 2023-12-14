#ifndef NETWORK_H
#define NETWORK_H
#include "Component.hpp"
#include <sstream>
#include <vector>

class Network {
private:
  std::vector<Component *> network;
public:
  void addComponent(Component *comp);
  void simulate(int iterations, int lines_to_print, double time_step) const;
  std::stringstream componentState(Component *component) const;
};
#endif
