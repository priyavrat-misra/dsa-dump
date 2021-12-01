// Character arrays and pointers
#include <iostream>

void log(const char* c) { // or `char c[]`
	while (*c != '\0') { // or 0
		std::cout << *c;
		c++;
	}
	std::cout << std::endl;
}

int main() {
	char s[20] = "Hello World!";
	log(s);
}
