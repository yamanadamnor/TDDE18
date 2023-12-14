#ifndef CAPACITOR_H
#define CAPACITOR_H
#include "Component.hpp"

class Capacitor: Component {
    private:
        double const stored_charge;
        double const capacitance;

    public:
        Capacitor();
        double getCurrent();
        double getVoltage();
};

#endif
