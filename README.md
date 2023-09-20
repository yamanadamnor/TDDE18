# tdde18
The labs are compiled with gcc with the following flags:
`g++ -std=c++17 -Wall -Wextra -Wpedantic`

## Lab 2
Compile the testing framework
`g++ -std=c++17 -Wall -Wextra -Wpedantic -c test_main.cpp`

Compile the test with the precompiled object file

`g++ -std=c++17 -Wall -Wextra -Wpedantic test_main.o Time.cpp time_test.cpp`