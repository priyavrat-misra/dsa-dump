// void pointers
#include <iostream>

int main() {
	int a = 1025;
	int *p = &a;
	void *p0 = p;  // no typecasting needed
	std::cout << "addr(p) = " << p << std::endl;
	std::cout << "addr(p0) = " << p0 << std::endl;
	std::cout << "val = " << *p0 << std::endl; // not possible
	// void pointers can't be dereferenced
	// as they aren't mapped to any particular data type.
	// pointer arithmetic is also not possible
}
