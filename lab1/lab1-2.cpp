#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
  float firstPrice{};
  float lastPrice{};
  float taxPercent{};
  float stride{};

  cout << "INPUT PART" << endl;
  cout << setw(10) << setfill('=') << "" << endl;

  while (true) {
    cout << left << setw(18) << setfill(' ') << "Enter first price"  << ": ";
    cin >> firstPrice;
    if (!(firstPrice > 0)) {
      cerr << "ERROR: First price must be at least 0 (zero) SEK" << endl;
    } else {
      break;
    }
  }

  
  while (true) {
    cout << setw(18) << "Enter last price" << ": ";
    cin >> lastPrice;

    if (lastPrice < firstPrice || lastPrice < 0) {
      cerr << "ERROR: Last price must be at least 0 (zero) SEK and higher than First price" << endl;
    } else {
      break;
    }
  }
  while (true) {
    cout << setw(18) << "Enter stride" << ": ";
    cin >> stride;
    if (!(stride >= 0.01f)) {
      cerr << "Stride must be atleast 0.01" << endl;
    } else {
      break;
    }
  } 
  
  while (true) {
    cout << setw(18) << "Enter tax percent" << ": ";
    cin >> taxPercent;
    if (taxPercent < 0 || taxPercent > 100) {
      cerr << "tax must be atleast 0 (zero) and at most 100.00" << endl;
    } else {
      break;
    }
  }

  cout << "\nTAX TABLE" << endl;
  cout << setw(9) << setfill('=') << "" << endl;
  cout << right << setw(12) << setfill(' ') << "Price";
  cout << setw(18) << "Tax";
  cout << setw(20) << "Price with tax" << endl;
  cout << setw(50) << setfill('-') << "" << endl;

  float price{};
  float tax{};
  float priceWithTax{};

  for (int i{0}; i*stride + firstPrice <= lastPrice; i++) {
    price = firstPrice + i*stride;
    tax = price * (taxPercent/100);
    priceWithTax = price + tax;

    cout << setw(12) << setfill(' ') << setprecision(2) << fixed << price;
    cout << setw(18) << setprecision(2) << tax;
    cout << setw(20) << setprecision(2) << priceWithTax << endl;
  }
}
