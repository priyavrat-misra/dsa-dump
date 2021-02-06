// Pointers and 2D arrays
#include <iostream>

int main(){
	int B[][3] = {{2, 3, 6}, {4, 5, 8}};
	// int *p = B; (not possible)
	int (*p)[3] = B;
	std::cout << "B =\t" << B << std::endl;
	std::cout << "&B[0] =\t" << &B[0] << std::endl;
	std::cout << "*B =\t" << *B << std::endl;
	std::cout << "B[0] =\t" << B[0] << std::endl;
	std::cout << "&B[0][0] =\t" << &B[0][0] << std::endl;
	std::cout << "B+1 =\t" << B+1 << std::endl;
	std::cout << "&B[1] =\t" << &B[1] << std::endl;
	std::cout << "*(B+1) =\t" << *(B+1) << std::endl;
	std::cout << "B[1] =\t" << B[1] << std::endl;
	std::cout << "&B[1][0] =\t" << &B[1][0] << std::endl;
	std::cout << "*(B+1)+2 =\t" << *(B+1)+2 << std::endl;
	std::cout << "B[1]+2 =\t" << B[1]+2 << std::endl;
	std::cout << "&B[1][2] =\t" << &B[1][2] << std::endl;
	std::cout << "*(*B+1) =\t" << *(*B+1) << std::endl;  // B[0][1]
	// tl;dr
	// B[i][j] = *(B[i]+j) = *(*(B+i)+j)
}
