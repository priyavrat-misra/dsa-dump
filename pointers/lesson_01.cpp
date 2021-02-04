#include <iostream>

int main(){
	int a = 5;
	int *p = &a;
	std::cout << "a = " << a << std::endl;
	std::cout << "p = " << p << std::endl;
	std::cout << "*p = " << *p << std::endl;
	std::cout << "&a = " << &a << std::endl;
	std::cout << "size of a = " << sizeof(a) << std::endl;
	std::cout << "size of p = " << sizeof(p) << std::endl;
}
