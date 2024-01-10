# Environment settings
Set the keyboard repeat rate to something more reasonable
```bash
xset r rate 175 50
```
Sets tab to 4 spaces in vim
```vim
set ts=4 sw=4 sts=4 et
set clipboard=unnamedplus
```

# General notes
Header gaurds
```cpp
#ifndef FILENAME_H
#define FILENAME_H
#endif
```


# Operator overloading
```cpp
// Has to be a non-member function
ostream& operator<<(ostream &os, const T &object)
```

# Algorithms
A way of printing every element in a container using STL is to use `std::copy` and `std::ostream_iterator`:
```cpp
std::copy(begin_it, end_it, std::ostream_iterator<std::string>(std::cout, "\n")); ```
```
This copies every element from begin_it to end_it to the ostream_iterator which prints it to std::cout. The third argument is the delimiter.

---

```cpp
std::transform(begin_it, end_it, container_to_push_to, unary_op);
// binary_op has two parameters:
// element, element
std::transform(begin_it, end_it, begin_it2, container_to_push_to, binary_op);

// binary_op has two parameters:
// accumulator, element
std::reduce(begin_it, end_it, initial_value, binary_op);

```

# command-line arguments
```cpp
// int argc is the number of arguments passed to the program
// char* argv[] is an array of strings containing the arguments
int main(int argc, char *argv[]) { ... }
```

# Inheritance & polymorphism
when decaling a pure-virtual function in a class, the class becomes abstract. This means that every derived class must implement the virtual functions.

```cpp
class Date{
    protected:
        int year;
        int month;
        int date;
};
class YMD_Date : public Date {};
class MDY_Date : public date {
   private:
        std::string day;
};
```

To be able to append the derived classes YMD_date and MDY_date to the same container without slicing pointers must be used instead;

```cpp
// This will not work because Date is an abstract class
std::vector<Date>{
    YMD_Date{1970, 1, 1},
    MDY_Date{"Thursday", 1970, 1, 1},
    YMD_Date{2020, 2, 19},
    MDY_Date{"Thursday", 2020, 2, 19}
};

// Use pointers instead. Remember to free the memory when done
std::vector<Date*>{
    new YMD_Date{1970, 1, 1},
    new MDY_Date{"Thursday", 1970, 1, 1},
    new YMD_Date{2020, 2, 19},
    new MDY_Date{"Thursday", 2020, 2, 19}
};

```

---

```cpp
```