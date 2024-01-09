#include <iostream>

class Complex {
	public:
		Complex(double real, double imaginary): real(real), imaginary(imaginary) {};
		Complex operator+(const Complex &rhs) const;
		Complex operator*(const Complex &rhs);
		double getReal() const;
		double getImaginary() const;

	private:
		double real;
		double imaginary;
};

double Complex::getReal() const {
	return this->real;
}

double Complex::getImaginary() const {
	return this->imaginary;
}

std::ostream &operator<<(std::ostream &os, const Complex &num) {
	os << num.getReal()<< '+' << num.getImaginary() << "i";
	return os;
}

Complex Complex::operator+(const Complex &rhs) {
	Complex newComplex{real + rhs.getReal(), imaginary + rhs.getImaginary()};

	return newComplex;
}

Complex Complex::operator*(const Complex &rhs) {
	double newReal{real * rhs.getReal() - (imaginary * rhs.getImaginary())};
	double newImaginary{real * rhs.getImaginary() + (imaginary * rhs.getReal())};
	Complex newComplex{newReal, newImaginary};
	return newComplex;
}



int main()
{
    Complex a{1.0, 2.0};
    Complex const b{3.0, 4.0};

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;

    return 0;
}
