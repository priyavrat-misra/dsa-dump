// const with pointers
#include <iostream>

int main() {
	int x=1, y=1;
	
	const int* ptr0 = &x; // (pointer to const int)
	*ptr0 = y; // not possible, as *ptr0 is a read-only variable
	ptr0 = &y; // possible
	
	int* const ptr1 = &x; // or const* int ptr1 (const pointer to int)
	*ptr1 = y; // possible
	ptr1 = &y; // not possible, as ptr1 is a read-only location
	
	const int* const ptr2 = &x; // (const pointer to a const int)
	*ptr2 = y; // not possible, as *ptr2 is a read-only variable
	ptr2 = &y; // not possible, as ptr2 is a read-only location
}
