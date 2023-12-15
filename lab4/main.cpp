#include <iostream>
#include <string>

#include "Battery.hpp"
#include "Capacitor.hpp"
#include "Network.hpp"
#include "Resistor.hpp"

void network1(int iterations, int lines_to_print, double time_step, double battery_voltage) {
  Network network;
  Connection P, N, R124, R23;
  network.addComponent(new Battery("Bat", battery_voltage, &P, &N));
  network.addComponent(new Resistor("R1", 6.0, &P, &R124));
  network.addComponent(new Resistor("R2", 4.0, &R124, &R23));
  network.addComponent(new Resistor("R3", 8.0, &R23, &N));
  network.addComponent(new Resistor("R4", 12.0, &R124, &N));

  network.simulate(iterations, lines_to_print, time_step);
}

void network2(int iterations, int lines_to_print, double time_step, double battery_voltage) {
  Network network;
  Connection P, N, L, R;
  network.addComponent(new Battery("Bat", battery_voltage, &P, &N));
  network.addComponent(new Resistor("R1", 150.0, &P, &L));
  network.addComponent(new Resistor("R2", 50.0, &P, &R));
  network.addComponent(new Resistor("R3", 100.0, &L, &R));
  network.addComponent(new Resistor("R4", 300.0, &L, &N));
  network.addComponent(new Resistor("R5", 250.0, &N, &R));

  network.simulate(iterations, lines_to_print, time_step);
}

void network3(int iterations, int lines_to_print, double time_step, double battery_voltage) {
  Network network;
  Connection P, N, L, R;
  network.addComponent(new Battery("Bat", battery_voltage, &P, &N));
  network.addComponent(new Resistor("R1", 150.0, &P, &L));
  network.addComponent(new Resistor("R2", 50.0, &P, &R));
  network.addComponent(new Capacitor("C3", 1.0,&R, &L));
  network.addComponent(new Resistor("R4", 300.0, &L, &N));
  network.addComponent(new Capacitor("C5", 0.75, &N, &R));

  network.simulate(iterations, lines_to_print, time_step);
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    std::cout << "Please provide only four arguments" << std::endl;
  }
  int iterations{std::stoi(argv[1])};
  int lines_to_print{std::stoi(argv[2])};
  double time_step{std::stod(argv[3])};
  double battery_voltage{std::stod(argv[4])};

  network1(iterations, lines_to_print, time_step, battery_voltage);
  // std::cout << std::endl;
  // network2(iterations, lines_to_print, time_step, battery_voltage);
  // std::cout << std::endl;
  // network3(iterations, lines_to_print, time_step, battery_voltage);


  return 0;
}
