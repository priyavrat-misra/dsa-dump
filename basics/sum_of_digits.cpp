#include <iostream>

int main() {
	int n, sum = 0;
	std::cout << "Enter a number: ";
	std::cin >> n;
	while (n>0) {
		sum+=n%10;
		n/=10;
	}
	std::cout << "The sum of digits is " << sum << std::endl;
}
