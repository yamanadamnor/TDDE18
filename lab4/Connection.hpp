#ifndef TERMINAL_H
#define TERMINAL_H

class Connection {
public:
  Connection();
  double getCharge() const;
  void setCharge(double charge);

private:
  double charge;
};

#endif
