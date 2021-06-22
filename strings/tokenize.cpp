// tokenize a string wuth given delimiter
#include <iostream>
#include <string>
#include <cstring>

int main() {
	std::string str;
	char dlim[] = " ";
	std::cout << "Enter a string: ";
	std::getline(std::cin, str);

	char* token = std::strtok(&str[0], dlim);
	while (token!=NULL) {
		std::cout << token << std::endl;
		token = std::strtok(NULL, dlim);
	}
}
