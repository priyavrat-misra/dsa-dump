// Pointer as fuction arguments - call by reference
#include <iostream>

void Increment(int *p){
	*p += 1;
}
int main(){
	int a = 9;
	Increment(&a);
	std::cout << "a = " << a << std::endl;  // 10
}
