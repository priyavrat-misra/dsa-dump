// insert an element to the linked list
#include <iostream>

struct Node {
	int data;
	Node* next;
};

Node* insert(Node* head, int& d, unsigned& p) {
	Node *nn = new Node;
	nn->data = d;
	if (p < 2) {
		nn->next = head;
		return nn;
	} else {
		Node *temp = head;
		for (unsigned i = 0; i < p - 2; ++i)
			temp = temp->next;
		
		nn->next = temp->next;
		temp->next = nn;
	}
	return head;
}

void print(Node* t) {
	while (t) {
		std::cout << "-->" << t->data;
		t = t->next;
	}
	std::cout << std::endl;
}

void delete_ll(Node* t) {
	Node* temp = t->next;
	while (temp) {
		delete t;
		t = temp;
		temp = temp->next;
	}
	delete t;
}

int main() {
	int d, v = 1;
	unsigned p;
	char f;
	Node *head = NULL;
	while (true) {
		std::cout << "Enter value to insert: ";
		std::cin >> d;
		std::cout << "Enter insertion position (1-" << v++ << "): ";
		std::cin >> p;
		head = insert(head, d, p);
		print(head);
		std::cout << "Continue inserting more elements? (y/n): ";
		std::cin >> f;
		if (f == 'n') break;
	}

	delete_ll(head);
}
