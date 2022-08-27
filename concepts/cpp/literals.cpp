#include <iostream>

int main() {
	std::cout << (20 == 0x14) << std::endl;
	std::cout << (20 == 024) << std::endl;
	// '\' followed by 1, 2 or 3 octal digits,
	// the value represents the numerical value
	// of the character
	std::cout << "\110\145\154\154\157\12";
	std::cout << "\x48\x65\x6c\x6C\x6f\xA";
}
