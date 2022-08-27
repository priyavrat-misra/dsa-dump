#include <iostream>

void f1(const int& a) {
	std::cout << a << std::endl;
	std::cout << &a << std::endl;
}

void f2(const int& a, const double& b) {
	std::cout << b << std::endl;
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;
}

int main() {
	int a = 2;
	double b = 3.14;
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;
	std::cout << std::endl;
	f1(a);
	f1(a + 400*a);
	f1(40);
	std::cout << std::endl;
	f2(a, b);
	f2(a, b * 8);
	f2(2, 10);
}
