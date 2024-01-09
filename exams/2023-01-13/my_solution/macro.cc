#include <string>
#include <sstream>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>

/* Example:

$ ./a.out
I study at LiU
I study at Linköping University
The course FULL_COURSE taught me programming in C++
The course TDDE18 at Department of Computer and Information Science / Linköping University
taught me programming in C++
<ctrl+D>

 */

// Return a container of macros
std::map<std::string, std::string> define_macros(std::ifstream &ifs) {
	std::map<std::string, std::string> macros;
	std::string line;

	while(std::getline(ifs, line)) {
		const auto split_at{line.find(':')};
		std::string name{line.substr(0, split_at)};
		std::string def{line.substr(split_at + 1, std::string::npos)};
		macros[name] = def;
	}

	return macros;
}

std::string expand(std::string &line, std::map<std::string, std::string> &macros) {
	std::string expanded;
	std::istringstream line_stream{line};
	std::string word;

	// Base case
	if (macros.count(line) == 1) {
		return expanded + macros[line];
	}

	 while(std::getline(line_stream, word, ' ')) {
	 	if ( macros.count(word) == 1) {
	 		expanded += expand(macros[word], macros);
	 	} else {
	 		expanded += word + " ";
	 	}
	 }

	return expanded;
}

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
