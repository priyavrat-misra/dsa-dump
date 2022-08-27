// program to compute nCr (n choose r)
// nCr = (n-1)Cr + (n-1)C(r-1)
#include <iostream>

long nCr(const unsigned& n, const unsigned& r) {
	if (r == 0 or r == n)
		return 1;
	else
		return nCr(n - 1, r) + nCr(n - 1, r - 1);
}

int main() {
	unsigned n, r;
	std::cout << "Enter 'n' and 'r' (0 <= r <= n): ";
	if (std::cin >> n >> r && n >= r) {
		std::cout << "n choose r = " << nCr(n, r) << std::endl;
	} else {
		std::cerr << "Out of range." << std::endl;
	}
}
