// Pointers - bad practices

int* f1() {  //returning a pointer
	int a = 5;
	return &a;
}

int& f2() {  // returning a reference
	int a = 5;
	return a;
}

int main() {
	int* x = f1();
	int& y = f2();
}
