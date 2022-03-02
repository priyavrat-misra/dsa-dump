// reverse a string using stack
// time complexity: O(n)
// space complexity: O(n)
#include <iostream>
#include <stack>

void reverse(char* c) {
	std::stack<char> st;
	int n = 0;
	while (*c) {
		st.push(*c);
		++n;
		++c;
	}
	c -= n;
	for (int i = 0; i < n; ++i) {
		c[i] = st.top();
		st.pop();
	}
}

int main() {
	char c[21];
	std::cout << "Enter a string: ";
	std::cin >> c;
	reverse(c);
	std::cout << "Reversed string: "
		<< c << std::endl;
}
