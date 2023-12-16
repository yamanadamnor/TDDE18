#ifndef TERMINAL_H
#define TERMINAL_H

class Connection {
private:
  double charge;

public:
  Connection();
  double getCharge() const;
  void setCharge(double charge);
};

#endif
