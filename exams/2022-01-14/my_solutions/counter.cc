#include <string>
#include <iostream>
using namespace std;

class Counter {
    public:
        Counter(const string &name ,int value) : name(name), value(value) {};
        int operator+(int rhs) const {
            return value + rhs;
        };

        // Prefix
        Counter& operator++() {
            ++value;
            return *this;
        };

        // Postfix
        Counter operator++(int) {
            Counter old{*this};
            ++value;
            return old;
        };

        Counter& operator+=(int rhs) {
            value += rhs;
            return *this;
        };

        string getName() const { return name; }
        int getValue() const { return value; }

        void setValue(int newValue)  { value = newValue; }
    private:
        string name;
        int value;
};

Counter operator+(Counter &lhs, int rhs) {
    Counter copy{lhs};
    copy += rhs;
    return copy;
}

Counter operator+(int lhs, Counter &rhs) {
    return rhs += lhs;
}

ostream& operator<<(ostream &os, const Counter &rhs) {
    os << "[" << rhs.getName() << "]" << " = " << rhs.getValue();
    return os;
}

int main()
{
    Counter my_counter {"My Counter", 1};
    std::cout << my_counter << std::endl;

    std::cout << ++my_counter << std::endl;
    
    std::cout << my_counter++ << std::endl;

    my_counter += 3;
    std::cout << my_counter << std::endl;

    std::cout << (my_counter + 5) << std::endl;

    std::cout << (5 + my_counter) << std::endl;
}
