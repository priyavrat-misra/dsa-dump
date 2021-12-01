// Character Arrays
#include <iostream>
#include <cstring>

int main() {
	char c[] = "Hello World!";  // implicit null termination
	char d[] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};  // explicit null termination
	// '\0' can be replaced with 0
	char* e = "wxyz";  // will lead to a warning, can be fixed by using a `const`
	char f = 'f';

	std::cout << "c = " << c << std::endl;
	std::cout << "c = " << &c[0] << std::endl;
	std::cout << "c[6:] = " << &c[6] << std::endl;

	char* x = d;
	std::cout << "d = " << d << std::endl;
	x[5] = '?';
	std::cout << "d = " << d << std::endl;
	std::cout << "x = " << x << std::endl;

	// e[0] = 'a';  // not possible because
	// e is a pointer to a string literal which is stored as a compile time constant

	char* y = &f;
	std::cout << y << std::endl;  // will print until it finds a null

	std::cout << "sizeof(c) = " << sizeof(c) << std::endl;
	std::cout << "sizeof(d) = " << sizeof(d) << std::endl;
	std::cout << "sizeof(x) = " << sizeof(x) << std::endl;
	std::cout << "sizeof(e) = " << sizeof(e) << std::endl;
	std::cout << "strlen(c) = " << strlen(c) << std::endl;
	std::cout << "strlen(d) = " << strlen(d) << std::endl;
	std::cout << "strlen(x) = " << strlen(x) << std::endl;
	std::cout << "strlen(e) = " << strlen(e) << std::endl;
}
