#include <iostream>

struct Node {
	int data;
	Node* next;
};

void push(Node** tos, int& e) {
	Node* t = new Node;
	t->data = e;
	t->next = *tos;
	*tos = t;
}

int pop(Node** tos) {
	Node* t = *tos;
	int d = t->data;
	*tos = (*tos)->next;
	delete t;
	return d;
}

void print(Node* tos) {
	if (tos) {
		std::cout << tos->data << "|";
		print(tos->next);
	}
}

void del_stack(Node* tos) {
	if (tos) {
		del_stack(tos->next);
		delete tos;
	}
}

int main() {
	Node* tos = NULL;
	int choice = 0, e;
	while (choice != 3) {
		std::cout << std::endl;
		std::cout
			<< "0. Push an element\n"
			<< "1. Pop an element\n"
			<< "2. Print the stack\n"
			<< "3. Delete stack and exit\n"
			<< "Choose one (0, 1, 2 or 3): ";
		std::cin >> choice;
		switch (choice) {
			case 0:
				std::cout << "Enter a number to push: ";
				std::cin >> e;
				push(&tos, e);
				break;
			case 1:
				if (tos) {
					std::cout << "Element " << pop(&tos)
						<< " at top of stack deleted.\n";
				} else {
					std::cerr << "Noting in stack to pop."
						<< " Push an element first.\n";
				}
				break;
			case 2:
				std::cout << "Stack: ";
				print(tos);
				std::cout << std::endl;
				break;
			case 3:
				del_stack(tos);
				tos = NULL;
				break;
			default:
				std::cerr << "Not a valid choice, try again.\n";
				break;
		}
	}
}
