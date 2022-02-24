// Sieve of Eratosthenes
// time complexity: O(n*log(log(n)))
// space complexity: O(n)
#include <iostream>

int main() {
	int n;
	std::cout << "Enter a number: ";
	if (std::cin >> n && n > 1) {
		int* primes = new int[n+1];
		primes[0] = primes[1] = 0;
		for (int i = 2; i <= n; ++i)
			primes[i] = 1;
		for (int i = 2; i*i <= n; ++i) {
			if (primes[i]) {
				for (int j = 2; i*j <= n; ++j)
					primes[i*j] = 0;	
			}
		}
		std::cout << "Prime numbers <= " << n << " are:";
		for (int i = 2; i <= n; ++i)
			if (primes[i])
				std::cout << " " << i;
		std::cout << std::endl;
		delete[] primes;
	} else {
		std::cerr << "No prime <= " << n << std::endl;
	}
}
