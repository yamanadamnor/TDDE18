#include "Connection.hpp"

Connection::Connection() : charge{0} {}

double Connection::getCharge() const { return charge; }

void Connection::setCharge(double charge) { this->charge = charge; }
