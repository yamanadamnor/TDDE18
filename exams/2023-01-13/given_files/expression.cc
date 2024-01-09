#include <iostream>

int main()
{
    Number five{5};
    Number three{3};
    Number two{2};
    Multiplication multiplication{five, two};
    Addition addition{three, multiplication};
    std::cout << addition.eval() << std::endl;
}
