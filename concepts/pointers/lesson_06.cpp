// Pointers to Pointers
#include <iostream>

int main() {
	int x = 5;
	int *p = &x;
	int **q = &p;
	int ***r = &q;
	std::cout << "*p = " << *p << std::endl;
	std::cout << "**q = " << **q << std::endl;
	std::cout << "***r = " << ***r << std::endl;
	**q *= ***r*2;
	std::cout << "x = " << x << std::endl;  // 50
}
