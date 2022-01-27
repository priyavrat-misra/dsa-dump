// Pointers - bad practices

int* f1() {  // returning a pointer of a stack variable
	int a = 5;
	return &a;
}
// Note: it's fine if a heap address is returned

int& f2() {  // returning a reference
	int a = 5;
	return a;
}

int main() {
	int* x = f1();
	int& y = f2();
}
