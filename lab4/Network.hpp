#ifndef NETWORK_H
#define NETWORK_H
#include "Component.hpp"
#include <vector>

class Network {
private:
  std::vector<Component *> components;

public:
  // Destructor
  ~Network();
  void addComponent(Component *comp);
  void simulate(int iterations, int lines_to_print, double time_step) const;
  void advance(double time_step) const;
  const std::string getComponentsState() const;
  const std::string getHeader() const;
};
#endif
