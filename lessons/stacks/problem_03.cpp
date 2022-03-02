// check for balanced parenthesis
#include <iostream>
#include <stack>

bool check_parenthesis(char* e) {
	std::stack<char> s;
	while (*e) {
		if (*e == '(' || *e == '{' || *e == '[')
			s.push(*e);
		switch (*e) {
			case ')':
				if (s.top() == '(') s.pop();
				else return false;
				break;
			case '}':
				if (s.top() == '{') s.pop();
				else return false;
				break;
			case ']':
				if (s.top() == '[') s.pop();
				else return false;
				break;
		}
		++e;
	}
	return s.empty();
}

int main() {
	char exp[51];
	std::cout << "Enter an expression: ";
	std::cin >> exp;
	std::cout << (check_parenthesis(exp)
		? "Paranthesis are balanced."
		: "Paranthesis are imbalanced.")
		<< std::endl;
}
