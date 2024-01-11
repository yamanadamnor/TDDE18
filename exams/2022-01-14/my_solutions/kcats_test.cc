#include <iostream>
#include <stdexcept>

#include "kcats.h"
#include "kcats.h" // Test include guards

int main()
{
    KCats kcats{};
    int value{};
    while (std::cin >> value)
    {
        kcats.push(value);
    }

    while (!kcats.empty())
    {
        std::cout << "hej" << std::endl;
        std::cout << kcats.pop() << ' ';
    }
    std::cout << std::endl;
}
