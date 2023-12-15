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
  Component(const std::string &&name, Connection *positive, Connection *negative);
 
  // Virtual destructor
  // virtual ~Component();

  virtual void simulate(double time_step);
  virtual double getCurrent() const;
  double getVoltage() const;

  const std::string &getName() const;
};

#endif
