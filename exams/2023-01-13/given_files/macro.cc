#include <string>
#include <iostream>
#include <fstream>

// Add your functions here

/* Example:

$ ./a.out
I study at LiU
I study at Linköping University
The course FULL_COURSE taught me programming in C++
The course TDDE18 at Department of Computer and Information Science / Linköping University
taught me programming in C++
<ctrl+D>

 */

// You may NOT modify the main function
int main()
{   
    std::ifstream ifs { "MACROS.txt" };

    // auto will become the type of whatever define_macros defines as the return type
    // so it is up to you to decide what type type this variable should be.
    auto macros { define_macros(ifs) };

    std::string line;
    while (std::getline(std::cin, line))
    {        
        std::cout << expand(line, macros) << std::endl;
    }
    
}
