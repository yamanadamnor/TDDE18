# vim settings
xset r rate 175 50
set ts=4 sw=4 sts=4 et

# Operator overloading
ostream& operator<<(ostream &os, const T &object)
Cannot be member function and has to be a non-member function

# Algorithms
std::transform(begin_it, end_it, container_to_push_to, unary_op);
std::transform(begin_it, end_it, begin_it2, container_to_push_to, binary_op);

std::reduce(begin_it, end_it, initial_value, binary_op);
binary_op has two parameters:
    accumulator, element

# command-line arguments
int main(int argc, char *argv[]) {}
argc är antalet argument
argv är en array av alla argument

