#include <iostream>

int main() {
	int a = 10;
	int *p = &a;
	std::cout << "a = " << a << std::endl;
	*p += 2;
	std::cout << "a = " << a << std::endl;
}
