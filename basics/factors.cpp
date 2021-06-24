#include <iostream>

int main() {
	int n;
	std::cout << "Enter a natural number: ";
	if (std::cin >> n && n >= 1) {
		std::cout << "The factor(s):";
		for (int i = 1; i*i <= n; ++i) {
			if (n%i == 0) {
				std::cout << " " << i;
				if (n/i != i)
					std::cout << " " << n/i;
			}
		}
		std::cout << std::endl;
	} else {
		std::cout << "That's not a natural number!" << std::endl;
	}
}
