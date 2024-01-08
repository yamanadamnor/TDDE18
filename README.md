# TDDE18
It is recommended to use the following alias for compiling the labs:

```bash
alias w++17="g++ -std=c++17 -Wall -Wextra -Wpedantic -Weffc++ -Wold-style-cast"
```
both g++ and clang++ works with this alias.

## Lab 2
Compile the testing framework which should yields a precompiled object file `test_main.o`
```bash
w++17 -c test_main.cpp
```

Compile the test with the precompiled object file
```bash
w++17 test_main.o Time.cpp time_test.cpp
```
## Lab 3
Compile the testing framework which should yields a precompiled object file `test_main.o`
```bash
w++17 -c test_main.cpp
```

## Lab 4
Compile the lab:
```bash
w++17 Battery.cpp Capacitor.cpp Component.cpp Connection.cpp Network.cpp Resistor.cpp main.cpp
```
## Lab5 
Compile the lab:
```bash
w++17 main.cpp
```
Run the program
```bash
./a.out <input file> FLAGS
FLAGS:
--print                            Prints every word in <input file> separated by spaces
--frequency                        Prints frequency table of <input file> in descending order of occurance
--table                            Prints frequency table of <input file> in lexicographical order
--substitute=<oldWord>+<newWord>   Substitutes every occurance of <oldWord> by <newWord> in content provided by <input file>
--remove=<word>                    Removes every occurance of <word> in content provided by <input file>
```
