#include <iostream>
#include <stack>
using namespace std;

// #include "min_stack_O_n.h"
#include "min_stack_O_1.h"

int main() {
	MinStack* stk = new MinStack;
	int val, choice;
	while (choice != 5) {
		cout
			<< "1. Push an element\n"
			<< "2. Pop an element\n"
			<< "3. Get min element\n"
			<< "4. Get top element\n"
			<< "5. Exit\n"
			<< "Choose (1, 2, 3, 4 or 5): ";
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "Enter element to push: ";
				cin >> val;
				stk -> push(val);
				break;
			case 2:
				stk -> pop();
				break;
			case 3:
				cout << stk -> getMin() << endl;
				break;
			case 4:
				cout << stk -> top() << endl;
				break;
			case 5:
				delete stk;
				break;
			default:
				cerr << "Not a valid choice. Try Again." << endl;
				break;
		}
		cout << endl;
	}
}
