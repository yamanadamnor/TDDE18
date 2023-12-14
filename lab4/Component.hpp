#ifndef COMPONENT_H
#define COMPONENT_H
#include "Connection.hpp"
#include <string>

class Component {
public:
  Connection *positive{};
  Connection *negative{};
  std::string name{};

  virtual double getCurrent() const;
};

#endif
