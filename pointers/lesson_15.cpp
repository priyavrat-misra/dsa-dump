// Function Pointers
#include <cstdio>

int Add(int a, int b) {
	return a + b;
}

void PrintHelloWorld() {
	printf("Hello World!\n");
}

void Greet(char* name) {
	printf("Hello %s\n", name);
}

int main() {
	int c;
	int (*p)(int, int);	
	p = Add;  // or &Add
	c = p(2, 3); // dereferencing and executing the function
	printf("%d\n", c);
	void (*hw)() = PrintHelloWorld;
	hw();
	void (*g)(char*) = Greet;
	g("foobar");
}
