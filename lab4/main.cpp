#include "Battery.hpp"
#include "Capacitor.hpp"
#include "Network.hpp"
#include "Resistor.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void network1(int iterations, int lines_to_print, double time_step,
              double battery_voltage) {
  Network network;
  Connection P;
  Connection N;
  Connection R124;
  Connection R23;
  network.addComponent(new Battery("Bat", battery_voltage, &P, &N));
  network.addComponent(new Resistor("R1", 6.0, &P, &R124));
  network.addComponent(new Resistor("R2", 4.0, &R124, &R23));
  network.addComponent(new Resistor("R3", 8.0, &R23, &N));
  network.addComponent(new Resistor("R4", 12.0, &R124, &N));

  network.simulate(iterations, lines_to_print, time_step);
}

void network2(int iterations, int lines_to_print, double time_step,
              double battery_voltage) {
  Network network;
  Connection P;
  Connection N;
  Connection L;
  Connection R;
  network.addComponent(new Battery("Bat", battery_voltage, &P, &N));
  network.addComponent(new Resistor("R1", 150.0, &P, &L));
  network.addComponent(new Resistor("R2", 50.0, &P, &R));
  network.addComponent(new Resistor("R3", 100.0, &L, &R));
  network.addComponent(new Resistor("R4", 300.0, &L, &N));
  network.addComponent(new Resistor("R5", 250.0, &N, &R));

  network.simulate(iterations, lines_to_print, time_step);
}

void network3(int iterations, int lines_to_print, double time_step,
              double battery_voltage) {
  Network network;
  Connection P;
  Connection N;
  Connection L;
  Connection R;
  network.addComponent(new Battery("Bat", battery_voltage, &P, &N));
  network.addComponent(new Resistor("R1", 150.0, &P, &L));
  network.addComponent(new Resistor("R2", 50.0, &P, &R));
  network.addComponent(new Capacitor("C3", 1.0, &L, &R));
  network.addComponent(new Resistor("R4", 300.0, &L, &N));
  network.addComponent(new Capacitor("C5", 0.75, &N, &R));

  network.simulate(iterations, lines_to_print, time_step);
}

void printHelp() {
  cerr << "./a.out ";
  cerr << "<INT iterations> ";
  cerr << "<INT lines_to_print>";
  cerr << "<DOUBLE time_step>";
  cerr << "<DOUBLE battery_voltage>";
  cerr << endl;
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    cerr << "Please provide only four arguments" << endl;
    printHelp();
    return -1;
  }
  int iterations{};
  int lines_to_print{};
  double time_step{};
  double battery_voltage{};

  try {
    iterations = stoi(argv[1]);
    if (iterations < 0) {
      throw invalid_argument("Invalid argument: " + to_string(iterations) +
                             " <iterations> must be a positive INTEGER");
    }
  } catch (invalid_argument &err) {
    cerr << err.what() << endl;
    cerr << "First argument <iterations> must be of type INTEGER" << endl;
    return -1;
  }

  try {
    lines_to_print = stoi(argv[2]);
    if (lines_to_print < 0) {
      throw invalid_argument("Invalid argument: " + to_string(lines_to_print) +
                             " <lines_to_print> must be a positive INTEGER");
    }
  } catch (invalid_argument &err) {
    cerr << err.what() << endl;
    cerr << "Second argument <lines_to_print> must be of type INTEGER" << endl;
    return -1;
  }

  try {
    time_step = stod(argv[3]);
    if (time_step < 0) {
      throw invalid_argument("Invalid argument: " + to_string(time_step) +
                             " time_step must be a positive DOUBLE");
    }
  } catch (invalid_argument &err) {
    cerr << err.what() << endl;
    cerr << "Third argument <time_step> must be of type DOUBLE" << endl;
    return -1;
  }

  try {
    battery_voltage = stod(argv[4]);
  } catch (invalid_argument &err) {
    cerr << "Fourth argument <battery_voltage> must be of type DOUBLE" << endl;
    return -1;
  }

  network1(iterations, lines_to_print, time_step, battery_voltage);
  cout << endl;
  network2(iterations, lines_to_print, time_step, battery_voltage);
  cout << endl;
  network3(iterations, lines_to_print, time_step, battery_voltage);

  return 0;
}
