// Function Pointers
#include <cstdio>

int Add(int a, int b) {
	return a + b;
}

void PrintHelloWorld() {
	printf("Hello World!\n");
}

void Greet(const char* name) {
	printf("Hello %s\n", name);
}

int main() {
	int c;
	int (*p)(int, int);	
	p = Add;  // or &Add
	c = p(2, 3); // dereferencing and executing the function
	printf("%d\n", c);
	void (*hw)() = PrintHelloWorld;
	hw();  // or (*hw)();
	void (*g)(const char*) = Greet;
	g("foobar");  // or (*g)("foobar");
}
