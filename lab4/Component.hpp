#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>

#include "Connection.hpp"

class Component {
protected:
  std::string name;
  Connection *positive;
  Connection *negative;

public:
  // Component constructor
  Component(const std::string &&name, Connection *positive,
            Connection *negative);

  // Virtual destructor
  virtual ~Component() = default;

  virtual void simulate(double time_step) = 0;
  virtual double getCurrent() const = 0;
  double getVoltage() const;

  const std::string &getName() const;
};

#endif
