#include <iostream>

// Implement your classes here

// You may *NOT* modify the main function
int main()
{
    Complex a{1.0, 2.0};
    Complex const b{3.0, 4.0};

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;

    return 0;
}
