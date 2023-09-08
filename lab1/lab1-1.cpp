#include <iomanip>
#include <iostream>
#include <limits>
#include <ostream>
#include <string>
using namespace std;

int main() {
  char c;
  int number;
  double bigReal;
  string str;

  cout << "Enter one integer: ";
  cin >> number;
  // Ignore 1000 chars or until delimiter
  // This is a way to flush the cin buffer
  cin.ignore(1000, '\n');
  cout << "You entered the number: " << number << endl;

  cout << "\nEnter four integers: ";
  cin >> number;
  cout << "You entered the numbers: " << number << " ";
  cin >> number;
  cout << number << " ";
  cin >> number;
  cout << number << " ";
  cin >> number;
  cout << number << " " << endl;

  cout << "\nEnter on integer and one real number: ";
  cin >> number
      >> bigReal;
  cin.ignore(1000, '\n');
  cout << "The real is: " << setfill(' ') << setw(11) << setprecision(3)
       << fixed << bigReal << endl;
  cout << "The integer is: " << setfill(' ') << setw(8) << number << endl;

  cout << "\nEnter one real and one integer number: ";
  cin >> bigReal
      >> number;
  cin.ignore(1000, '\n');
  cout << "The real is: " << setfill('.') << setw(11) << setprecision(3)
       << bigReal << endl;
  cout << "The integer is: " << setfill('.') << setw(8) << number << endl;

  cout << "\nEnter a character: ";
  cin >> c;
  cin.ignore(1000, '\n');
  cout << "You entered: " << c << endl;

  cout << "\nEnter a word: ";
  cin >> str;
  // The word length
  number = str.size();
  cout << "The word: '" << str << "' has " << number << " character(s)."
       << endl;

  cout << "\nEnter an integer and a word: ";
  cin >> number
      >> str;
  cin.ignore(1000, '\n');
  cout << "You entered: '" << number << "' and '" << str << "'." << endl;

  cout << "\nEnter an character and a word: ";
  cin >> c
      >> str;
  cin.ignore(1000, '\n');
  cout << "You entered the string '" << str << "' and the character '" << c
       << "'." << endl;

  cout << "\nEnter a word and a real number: ";
  cin >> str
      >> bigReal;
  cin.ignore(1000, '\n');
  cout << "You entered: '" << str << "' and '" << setprecision(3) << bigReal
       << "'." << endl;
  cout << "\nEnter a text-line: ";
  getline(cin, str);
  cout << "You entered: \"" << str << "\"." << endl;

  cout << "\nEnter a second line of text: ";
  getline(cin, str);
  cout << "You entered: \"" << str << "\"" << endl;

  cout << "\nEnter three words: ";
  cin >> str;
  cout << "You entered: \"" << str << " ";
  cin >> str;
  cout << str << " ";
  cin >> str;
  cout << str << "\'" << endl;
}
