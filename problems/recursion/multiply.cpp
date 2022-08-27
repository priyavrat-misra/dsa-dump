// mutiply 2 numbers without using multipication operator
#include <iostream>

int multiply(const int& a, const int& b) {
	if (b == 0)
		return 0;
	else if (b == 1)
		return a;
	else
		return a + multiply(a, b - 1);
}

int main() {
	int a, b;
	std::cout << "Enter 2 numbers: ";
	std::cin >> a >> b;
	std::cout << a << " * " << b << " = "
		<< multiply(a, b) << std::endl;
}
