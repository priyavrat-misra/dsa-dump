// compute the result given the exponent and the base
#include <iostream>

long pow(const int& b, const int& e) {
	if (e == 0)
		return 1;
	else {
		long h = pow(b, e/2);
		return e % 2 ? b * h * h : h * h;
	}
}

int main() {
	int b, e;
	std::cout << "Enter the base: ";
	std::cin >> b;
	std::cout << "Enter the exponent: ";
	if (std::cin >> e && e > 0) {
		std::cout << b << " raised to the power "
			<< e << " equals " << pow(b, e)
			<< "." << std::endl;
	} else {
		std::cerr << "Only supports whole numbers."
			<< std::endl;
	}
}
