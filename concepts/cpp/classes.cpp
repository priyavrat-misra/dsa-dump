#include <iostream>
using namespace std;

class ComplexNo {
	private:
		int real, imgn;
	public:
		ComplexNo() {
			cout << "Enter values of the real & imaginary part: ";
			cin >> real >> imgn;
		}

		ComplexNo(const int& real, const int& imgn) {
			this -> real = real;
			this -> imgn = imgn;
		}

		void print() {
			std::cout
				<< this
				<< ": "
				<< real
				<< " + "
				<< imgn
				<< "i"
				<< endl;
		}

		void add(const ComplexNo& c) {
			real += c.real;
			imgn += c.imgn;
		}

		void mul(const ComplexNo& c) {
			real = real * c.real - imgn * c.imgn;
			imgn = real * c.imgn + imgn * c.real;
		}

		~ComplexNo() {
			cout << this << ": Destructed." << endl;
		}
};

int main() {
	ComplexNo c1,
		  c2(1, 2),
		  c3(c1),  // copy constructor
		  c4 = c2;  // copy constructor
	c1.print();
	c2.print();
	c3.print();
	c4.print();

	c1.add(c1);
	c2.mul(c4);
	c4 = c3;
	c3 = c2;  // copy assignment operator
	c1.print();
	c2.print();
	c3.print();
	c4.print();

	ComplexNo *c5 = new ComplexNo(9, 8);
	ComplexNo *c6 = new ComplexNo(c4);  // copy constructor
	ComplexNo *c7 = new ComplexNo(*c5);
	(*c5) = (*c6);
	(*c6) = c1;

	c5 -> print();
	c6 -> print();
	c7 -> print();

	delete c5;
	delete c6;
	delete c7;
}
