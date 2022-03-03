// reverse a string without using stack
// time complexity: O(n)
// space complexity: O(1)
#include <iostream>
#include <stack>
#include <cstring>

void swap(char& i, char& j) {
	char c = i;
	i = j;
	j = c;
}

void reverse(char* c, const int& n) {
	int i = 0, j = n - 1;
	while (i < j)
		swap(c[i++], c[j--]);
}	

int main() {
	char c[21];
	std::cout << "Enter a string: ";
	std::cin >> c;
	reverse(c, strlen(c));
	std::cout << "Reversed string: "
		<< c << std::endl;
}
