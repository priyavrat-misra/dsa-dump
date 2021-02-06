// Character arrays and pointers
#include <iostream>

void Log(const char* c){
	while(*c != '\0'){
		std::cout << *c;
		c++;
	}
	std::cout << std::endl;
}

int main(){
	char s[20] = "Hello World!";
	Log(s);
}
