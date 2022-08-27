// tokenize a string with a given delimiter
#include <iostream>
#include <string>
#include <cstring>

int main() {
	std::string str;
	std::string dlim;
	std::cout << "Enter a string: ";
	std::getline(std::cin, str);
	std::cout << "Enter delimiter: ";
	std::getline(std::cin, dlim);

	char* token = std::strtok(&str[0], &dlim[0]);
	while (token!=NULL) {
		std::cout << token << std::endl;
		token = std::strtok(NULL, &dlim[0]);
	}
}
