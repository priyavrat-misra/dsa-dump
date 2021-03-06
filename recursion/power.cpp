// compute the result given the exponent and the base
#include <iostream>

long pow(const int& b, const int& e) {
	return e == 0 ? 1 : b * pow(b, e - 1);
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
