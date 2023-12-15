#include "Network.hpp"
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
using namespace std;

void Network::addComponent(Component *comp) { network.push_back(comp); }

void Network::simulate(int iterations, int lines_to_print, double time_step) const {
  int print_step{iterations / lines_to_print};
  cout << getHeader() << endl;

  for (int it{0}; it < iterations; it++) {
    stringstream component_state;

    for (Component *component : network) {
      component->simulate(time_step);
      component_state << getComponentState(component);
    }

    // Run the simulation with time_step on every component in the network
    // vector
    if (it % print_step == 0) {
      cout << component_state.str() << endl;
    }
  }
}

const std::string Network::getHeader() const {
  stringstream names;
  stringstream columns;

  for (Component *component : network) {
    names << setw(12) << right;
    names << component->getName();
    columns << setw(6) << "Volt";
    columns << setw(6) << "Curr";
  }

  // Combine the names with the columns to make the header
  names << endl << columns.str();
  return names.str();
}

const std::string Network::getComponentState(Component *component) const {
  stringstream ss;
  ss << fixed << right << setprecision(2);
  ss << setw(6) << component->getVoltage();
  ss << setw(6) << component->getCurrent();
  return ss.str();
}
