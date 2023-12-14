#include <iostream>
#include <string>
#include <vector>

#include "Battery.hpp"
#include "Capacitor.hpp"
#include "Network.hpp"
#include "Resistor.hpp"

int main(int argc, char *argv[]) {
  // vector<string> args{argv, argv + argc};
  // int iterations;
  // int lines_to_print;
  // double time_step;
  // double battery_voltage;
  //
  // cout << iterations << endl;
  // cout << lines_to_print << endl;
  // cout << time_step << endl;
  // cout << battery_voltage << endl;

  Network network1;
  Connection P1, N1, R124, R23;
  network1.addComponent(new Battery("Bat", 24.0, &P1, &N1));
  network1.addComponent(new Resistor("R1", 6.0, &P1, &R124));
  network1.addComponent(new Resistor("R2", 4.0, &R124, &R23));
  network1.addComponent(new Resistor("R3", 8.0, &R23, &N1));
  network1.addComponent(new Resistor("R4", 12.0, &R124, &N1));

  network1.simulate(200000, 10, 0.01);

  return 0;
}
