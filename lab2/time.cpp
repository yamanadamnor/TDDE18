#include <memory>
#include <iostream>
#include <string>
using namespace std;

// TODO: Operator overloading of the six comparison operators
// TODO: 


struct Time {
    int hour;
    int minute;
    int second;

    Time operator+(int incrementor) {
        // TODO: Increment time by incrementor seconds
    }
    Time operator-(int decrementor) {
        // TODO: Decrement time by incrementor seconds
    }

    Time& operator++() {
        // TODO: Increment time by 1 second
    }

    Time& operator--() {
        // TODO: Decrement time by 1 second
    }

    ostream& operator<<(ostream& os) {
        os << hour << ":" << minute << ":" << second;
        return os;
    }

    istream& operator>>(istream& is) {
        // Correct input in the format HH:MM:SS
        // TODO: Validate input 
        return is;
    }

    bool is_valid() {
    }

    string to_string() {
    }

    bool is_am () {

    }


};
