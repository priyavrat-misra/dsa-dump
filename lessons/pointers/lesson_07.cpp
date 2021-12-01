// Pointer as fuction arguments - call by reference
#include <iostream>

void increment(int *p) { // or int p[]
	*p += 1;
}

int main() {
	int a = 9;
	increment(&a);
	std::cout << "a = " << a << std::endl;  // 10
}
