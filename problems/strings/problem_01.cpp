// check if a given string is palindrome or not
#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cout << "Enter a string: ";
	std::getline(std::cin, s);
	if (s == std::string(s.rbegin(), s.rend()))
		std::cout << "It is palindrome." << std::endl;
	else
		std::cout << "It isn't palindrome." << std::endl;
}
