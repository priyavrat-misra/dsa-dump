#include <iostream>

int main() {
	int n, p;
	float r = 0, inc = 1;

	std::cout << "Enter a whole number: ";
	if (std::cin >> n && n>=0) {
		std::cout << "Enter the precision count: ";
		std::cin >> p;

		for (int i=0; i<=p; ++i) {
			while (r*r<=n) {
				r += inc;
			}
			r -= inc;
			inc /= 10;
		}

		std::cout << "The square root is: " << r << std::endl;
	} else {
		std::cout << "That's not a whole number!" << std::endl;
	}
}
