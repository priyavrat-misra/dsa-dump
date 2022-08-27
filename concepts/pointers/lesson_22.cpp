// const, pointers and references

void f1(const int* a) {  // const pointer
	++(*a);  // will lead to an error
}

void f2(const int& a) {  // const reference
	++a;  // will lead to an error
}

int main() {
	int x = 5;
	f1(&x);
	f2(x);
}

// using `const` makes a variable,
// a location or a reference read-only
