#include <iostream>
class Node {
	public:
        // Pure virtual function
        virtual ~Node() = default;
		virtual int eval() const = 0;
};
class Number : public Node {
	public:
		Number(int data) : data(data) {};
		int eval() const  override {
			return data;
		}
	private:
		int data;
};
class Binary : public Node {
	public:
		Binary(Node &left, Node &right) : left(left), right(right) {};
	protected:
        Node& left;
		Node& right;
};
class Addition : public Binary {
	public:
		Addition(Node &left, Node &right) : Binary(left, right) {};
		int eval() const {
			return left.eval() + right.eval();
		}
};
class Multiplication : public Binary {
	public:
		Multiplication(Node &left, Node &right) : Binary(left, right) {};
		int eval() const override {
			return left.eval() * right.eval();
		}
};

int main()
{
    Number five{5};
    Number three{3};
    Number two{2};
    Multiplication multiplication{five, two};
    Addition addition{three, multiplication};
    std::cout << addition.eval() << std::endl;
}
