# vim settings
xset r rate 175 50
set ts=4 sw=4 sts=4 et

# Operator overloading
ostream& operator<<(ostream &os, const T &object)
Cannot be member function and has to be a non-member function

# Algorithms
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
// int argc is the number of arguments
// char *argv is an array of char pointers, i.e. an array of strings containing the arguments

int main(int argc, char *argv[]) {
    // ...
}
```

# Inheritance & polymorphism
when decaling a pure-virtual function in a class, the class becomes abstract. This means that every derived class must implement the virtual functions.

````cpp
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

````cpp
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
