#include "Network.hpp"
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
using namespace std;

Network::~Network() {
  for (Component *component : components) {
    delete component;
  }
}

void Network::addComponent(Component *comp) { components.push_back(comp); }

void Network::simulate(int iterations, int lines_to_print,
                       double time_step) const {
  int print_step{iterations / lines_to_print};
  cout << getHeader() << endl;

  for (int it{0}; it < iterations; it++) {
    stringstream component_state;

    advance(time_step);
    component_state << getComponentsState();

    // Run the simulation with time_step on every component in the network
    // vector
    if (it % print_step == 0) {
      cout << component_state.str() << endl;
    }
  }
}

void Network::advance(double time_step) const {
  for (Component *component : components) {
    component->simulate(time_step);
  }
}

const std::string Network::getHeader() const {
  stringstream names;
  stringstream columns;

  for (Component *component : components) {
    names << setw(12) << right;
    names << component->getName();
    columns << setw(6) << "Volt";
    columns << setw(6) << "Curr";
  }

  // Combine the names with the columns to make the header
  names << endl << columns.str();
  return names.str();
}

const std::string Network::getComponentsState() const {
  stringstream ss;
  ss << fixed << right << setprecision(2);
  for (Component *component : components) {
    ss << setw(6) << component->getVoltage();
    ss << setw(6) << component->getCurrent();
  }
  return ss.str();
}
