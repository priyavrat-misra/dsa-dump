#include <iostream>

struct Node {
	int data;
	Node* next;
};

bool empty(Node* tos) {
	return tos == NULL;
}

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
	while (choice != 4) {
		std::cout << std::endl
			<< "1. Push an element\n"
			<< "2. Pop an element\n"
			<< "3. Print the stack\n"
			<< "4. Delete stack and exit\n"
			<< "Choose one (1, 2, 3 or 4): ";
		std::cin >> choice;
		switch (choice) {
			case 1:
				std::cout << "Enter a number to push: ";
				std::cin >> e;
				push(&tos, e);
				break;
			case 2:
				if (tos) {
					std::cout << "Element " << pop(&tos)
						<< " at top of stack deleted.\n";
				} else {
					std::cerr << "Noting in stack to pop."
						<< " Push an element first.\n";
				}
				break;
			case 3:
				if (!empty(tos)) {
					std::cout << "Stack: ";
					print(tos);
				} else {
					std::cout << "Stack is empty.";
				}
				std::cout << std::endl;
				break;
			case 4:
				del_stack(tos);
				tos = NULL;
				break;
			default:
				std::cerr << "Not a valid choice, try again.\n";
				break;
		}
	}
}
