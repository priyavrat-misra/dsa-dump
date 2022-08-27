// print 1st 'n' numbers in increasing & decreasing order
#include <iostream>

void decr(const int& n) {
	if (n) {
		std::cout << n << '\t';
		decr(n - 1);
	}
}

void incr(const int& n) {
	if (n) {
		incr(n - 1);
		std::cout << n << '\t';
	}
}

int main() {
	int n;
	std::cout << "Enter a positive number: ";
	if (std::cin >> n && n > 0) {
		decr(n);
		std::cout << std::endl;
		incr(n);
		std::cout << std::endl;
	} else {
		std::cerr << "Not a positive number." << std::endl;
	}
}
