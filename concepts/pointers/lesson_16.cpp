// Function pointers and callbacks
#include <cstdio>

void A() {
	printf("Hello\n");
}

void B(void (*ptr)()) {  // function pointer as argument
	ptr();  // callback function that "ptr" points to
}

int main() {
	B(A);  // A is callback function
}
