#include <iostream>

int main() {
	int bin, dec = 0, p = 1;
	std::cout << "Enter a binary no: ";
	std::cin >> bin;
	while (bin>0) {
		dec += (bin%10)*p;
		bin/=10;
		p*=2;
	}
	std::cout << "The decimal equivalent is " << dec << std::endl;
}
