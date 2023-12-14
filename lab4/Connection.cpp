#include "Connection.hpp"

double Connection::getCharge() const {
    return this->charge;
};

void Connection::setCharge(double charge) {
    this->charge = charge;
}
