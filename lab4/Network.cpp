#include <iostream>
#include <sstream>
#include <iomanip>
#include "Network.hpp"
using namespace std;

void Network::addComponent(Component *comp) { network.push_back(comp); }

void Network::simulate(int iterations, int lines_to_print, double time_step) const {
  int print_step{iterations/lines_to_print};

  for (int it{0}; it < iterations; it++) {
    stringstream component_state;

    if (it % print_step == 0) {
      cout << component_state.str() << endl;
    }
    for (int i{0}; i < network.size(); i++) {
      // Run the simulation with time_step on every component in the network
      // vector
      network[i]->simulate(time_step);
      this->componentState(network[i]);
    }

  }

}
stringstream Network::componentState(Component *component) const {
  stringstream ss;
  ss << setprecision(4);
  ss << component->getVoltage() << " " << component->getCurrent();
  return ss;

}
