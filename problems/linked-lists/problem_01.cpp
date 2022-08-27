// reverse a linked list - iterative solution
// time complexity: O(n)
// space complexity: O(1)
#include <iostream>

struct Node {
	int data;
	Node* next;
};

void print(Node* t) {
	if (t) {
		std::cout << "-->" << t->data;
		print(t->next);
	}
}

void reverse(Node** head) {
	Node *curr = *head, *prev = NULL, *next;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

void del(Node* t) {
	if (t) {
		del(t->next);
		delete t;
	}
}

int main() {
	Node* head = NULL;
	int d;
	char c;
	while (true) {
		Node* t = new Node;
		std::cout << "Enter a number: ";
		std::cin >> d;
		t->data = d;
		t->next = head;
		head = t;
		print(head);
		std::cout << "\nEnter more? (y/n): ";
		std::cin >> c;
		if (c == 'n') break;
	}
	std::cout << "The reversed list is: ";
	reverse(&head);
	print(head);
	std::cout << std::endl;
	del(head);
}
