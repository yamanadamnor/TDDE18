#include <string>
#include <iostream>

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
