# Environment settings
Set the keyboard repeat rate to something more reasonable
```bash
xset r rate 175 50
```
Sets tab to 4 spaces in vim
```vim
set ts=4 sw=4 sts=4 et
set clipboard=unnamedplus
set number relativenumber 
```

# General notes
Header gaurds
```cpp
#ifndef FILENAME_H
#define FILENAME_H
#endif
```
Opening a file using fstream
```cpp
ifstream ifs{};
string line;
ifs.open("filename");

getline(inputstream, output_string, delimiter);

getline(ifs, line, " ");

// In loop
while(getline(ifs, line)) { ... }

```


# Operator overloading
```cpp
// Has to be a non-member function
ostream& operator<<(ostream& os, const T& object)
istream& operator>>(istream& is, T& object);

T operator+(const T& object, int incrementor);
T operator-(const T& object, int decrementor);

// If member funtion remove the reference to object T
// Prefix operators
T& operator++(T& object);
T& operator--(T& object);

// Postfix operators
T operator++(T& object, int);
T operator--(T& object, int);

// Comparison operators
bool operator>(const T& lhs, const T& rhs);

// Copy assignment operator
T& T::operator=(const T &rhs) {
  // Self check
  if (this == &rhs)
    return *this;

  clearList(*this);
  // Copies the content of rhs to this
  this->deepCopy(rhs);

  return *this;
}

// Move assignment operator
T& T::operator=(T &&rhs) {
  // Self check
  if (this == &rhs)
    return *this;

  clearList(*this);

  // Moves the content of rhs to this
  this->head = rhs.head;
  rhs.head = nullptr;

  return *this;
}

ostream& operator<<(ostream &os, const T &object)

// Prefix operators
Time &operator++(Time &time);
Time &operator--(Time &time);

// Postfix operators
Time operator++(Time &time, int);
Time operator--(Time &time, int);

// Comparison operators
bool operator>(const Time &lhs, const Time &rhs);
```

# Algorithms
A way of printing every element in a container using STL is to use `std::copy` and `std::ostream_iterator`:

This copies every element from begin_it to end_it to the ostream_iterator which prints it to std::cout. The third argument is the delimiter.
```cpp
std::copy(begin_it, end_it, std::ostream_iterator<std::string>(std::cout, "\n"));
```

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
```cpp
// Read for cin and append it to gifts vector
// This read cin from beginning until it matches the end iterator which is
// retured by the constructor of istream_iterator
vector<string> gifts { istream_iterator<string>{cin}, istream_iterator<string>{} };

// Vector of strings
vector<string> wishlist{ "Book", "Bicycle", "Laptop", "Socks", "Decorations", "Candy" };

// Remove every element in wishlist if it exists in gifts
wishlist.erase(
    remove_if(wishlist.begin(), wishlist.end(), [&gifts](const string &el){
        return find(gifts.begin(), gifts.end(), el) != gifts.end();
    }),
    wishlist.end()
);
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

A virtual destructor is usually required in a base class.

```cpp

  // Forcing the compiler to generate a destructor
  virtual ~Component() = default;

  // Disabling the implicit destructor
  virtual ~Component() = delete;

  // Copy constructor
  SortedList(const SortedList &list);

  // Move constructor
    SortedList::SortedList(SortedList &&refList) {
      // Move refList to this, example below
      this->head = refList.head;
      refList.head = nullptr;
    }

  // Destructor
  ~SortedList();

  // Copy assignment operator
  SortedList &operator=(const SortedList &rhs);

  // Move assignment operator
  SortedList &operator=(SortedList &&rhs);

Shape* ptr {...};
Cuboid* cuboid {dynamic_cast<Cuboid*>(ptr)};
if (cuboid != nullptr)
{
    // only print volume if it is a cuboid
    cout << cuboid->volume() << endl;
}
```
