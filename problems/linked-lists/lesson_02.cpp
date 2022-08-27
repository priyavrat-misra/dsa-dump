// linked list with 3 nodes
#include <iostream>

struct Node {
	int data;
	Node *next;
};

int main() {
	Node* temp = new Node;
	temp->data = 2;
	Node *t = temp, *head = temp;

	temp = new Node;
	t->next = temp;
	temp->data = 4;
	t = temp;

	temp = new Node;
	t->next = temp;
	temp->data = 6;
	temp->next = NULL;

	// traverse the linked list
	t = head;
	while (t != NULL) {
		std::cout << t << "\t" << t->data << std::endl;
		t = t->next;
	}
}
