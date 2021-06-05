// Pointer arithmetic
#include <iostream>

int main() {
	int i = 10;
	double d = 12.0;
	int *ip = &i;
	double *id = &d;
	std::cout << "ip = " << ip << std::endl;
	std::cout << "value at ip = " << *ip << std::endl;
	std::cout << "size of int = " << sizeof(int) << std::endl;
	std::cout << "ip+1 = " << ip + 1 << std::endl;
	std::cout << "value at ip+1 = " << *(ip+1) << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "id = " << id << std::endl;
	std::cout << "value at id = " << *id << std::endl;
	std::cout << "size of double = " << sizeof(double) << std::endl;
	std::cout << "id+1 = " << id + 1 << std::endl;
	std::cout << "value at id+1 = " << *(id+1) << std::endl;
}
