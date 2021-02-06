// Character Arrays
#include <iostream>
#include <cstring>

int main(){
	char c[] = "Hello World!";
	char d[] = {'H', 'e', 'l', 'l', 'o', '\0'};
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "sizeof(c) = " << sizeof(c) << std::endl;
	std::cout << "sizeof(d) = " << sizeof(d) << std::endl;
	std::cout << "strlen(c) = " << strlen(c) << std::endl;
	std::cout << "strlen(d) = " << strlen(d) << std::endl;
}
