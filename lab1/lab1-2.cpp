#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

template<typename T> void printElement(T t, const int& width) {
  cout << left << setw(width) << setfill(' ') << t;
}

int main() {
  float firstPrice, lastPrice, taxPercent, stride;

  cout << "INPUT PART\n==========" << endl;

  do {
    cout << left << setw(18) << setfill(' ') << "Enter first price"  << ": ";
    cin >> firstPrice;

    if (firstPrice < 0) {
      cerr << "ERROR: First price must be at least 0 (zero) SEK" << endl;
    }
  }
  while (!(firstPrice > 0));

  do {
    cout << setw(18) << setfill(' ') << "Enter last price" << ": ";
    cin >> lastPrice;

    if (lastPrice < firstPrice || lastPrice < 0) {
      cerr << "ERROR: Last price must be at least 0 (zero) SEK and higher than First price" << endl;
    }
  }
  while (lastPrice < firstPrice || lastPrice < 0);


  do {
    cout << setw(18) << setfill(' ') << "Enter stride" << ": ";
    cin >> fixed >> setprecision(2) >> stride;

    // Workaround the floating point rounding errors
    if (stride < 0.009){
      cerr << "Stride must be atleast 0.01" << endl;
    }
  } 
  // Workaround the floating point rounding errors
  while (stride < 0.009);

  do {
    cout << setw(18) << setfill(' ') << "Enter tax percent" << ": ";
    cin >> taxPercent;

    if (taxPercent < 0 || taxPercent > 100) {
      cerr << "tax must be atleast 0 (zero) and at most 100.00" << endl;

    }
  }
  while (taxPercent < 0 || taxPercent > 100);

  cout << "\nTAX TABLE\n=========" << endl;
  cout << right << setw(12) << setfill(' ') << "Price";
  cout << setw(18) << setfill(' ') << "Tax";
  cout << setw(20) << setfill(' ') << "Price with tax" << endl;

  cout << setw(50) << setfill('-') << "" << endl;

  float price, tax, priceWithTax;
  int i = 0;

  while (firstPrice + i*stride < lastPrice) {
    price = firstPrice + i*stride;
    tax = price * (taxPercent/100);
    priceWithTax = price + tax;

    cout << setw(12) << setfill(' ') << setprecision(2) << fixed << price;
    cout << setw(18) << setfill(' ') << setprecision(2) << tax;
    cout << setw(20) << setfill(' ') << setprecision(2) << priceWithTax << endl;

    i++;
  }

}
