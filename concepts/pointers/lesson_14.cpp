// Pointers as function returns
#include <cstdio>
#include <cstdlib>

void PrintHelloWorld() {
	printf("Hello World!\n");
}

int* Add(int* a, int* b) {
	int* c = (int*) malloc(sizeof(int));
	*c = *a + *b;
	return c;
}

int main() {
	int a = 2, b = 4;
	int* ptr = Add(&a, &b);
	PrintHelloWorld();
	printf("Sum = %d\n", *ptr);
	free(ptr);
	ptr = nullptr;
}
