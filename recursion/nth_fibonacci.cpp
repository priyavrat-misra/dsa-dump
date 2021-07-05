// nth fibonacci
#include <iostream>

int nth_fib(int n) {
	if (n == 0 || n == 1)
		return n;
	else
		return nth_fib(n - 2) + nth_fib(n - 1);
}

int main() {
	int n;
	std::cout << "Enter 'n': ";
	if (std::cin >> n && n > 0) {
		std::cout << "The nth fibonacci is: "
			<< nth_fib(n - 1) << std::endl;
	} else {
		std::cerr << "'n' must be positive."
			<< std::endl;
	}
}
