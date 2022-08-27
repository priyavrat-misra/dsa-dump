#include <iostream>

int main() {
	unsigned b, n, m;
	std::cout << "Enter values for b, n, m"
		" in (b^n mod m): ";
	if (std::cin >> b >> n >> m) {
		int t = 1, x = 1, power = b % m;
		while (t <= n) {
			if (t&n) x = (x * power) % m;
			power = (power * power) % m;
			t = t << 1;
		}
		std::cout << b << "^" << n << " mod " << m
			<< " = " << x << std::endl;
	} else {
		std::cerr << "Only positive numbers." << std::endl;
	}
}
