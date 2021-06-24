// passing arrays to functions
#include <iostream>

void func_1d(int *A) {}  // or A[]

void func_2d(int (*B)[3]) {}  // or B[][3]

void func_3d(int (*C)[3][2]) {}  // or C[][3][2]

int main() {
	int A[] = {1,2};
	int B[][3] = {{1,2,3}, {2,2,1}};
	int C[][3][2] = {
		{{2,4},{1,5},{7,2}},
		{{6,8},{2,9},{4,0}}
	};
	func_1d(A);  // A returns int*
	func_2d(B);  // B returns int (*)[3]
	func_3d(C);  // C returns int (*)[3][2]
}
