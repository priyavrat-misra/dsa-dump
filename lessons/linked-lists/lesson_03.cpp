// linked list with multiple nodes
#include <iostream>

struct Node {
	int data;
	Node *next;
};

int main() {
	int n;
	std::cout << "Enter number of nodes: ";
	if (std::cin >> n && n > 0) {
		Node *temp = new Node;
		std::cout << "Enter data for node 1: ";
		std::cin >> temp->data;
		Node *head = temp, *t = temp;
		
		for (int i = 1; i < n; ++i) {
			temp = new Node;
			std::cout << "Enter data for node "
				<< i + 1 << ": ";
			std::cin >> temp->data;
			t->next = temp;
			t = temp;
		}
		t->next = NULL;
		
		t = head;
		std::cout << "Address of the nodes:" << std::endl; 
		while (t) {  // != NULL
			std::cout << t << std::endl;
			t = t->next;
		}

		// delete the linked list
		t = head;
		temp = t->next;
		while (temp) {  // != NULL
			delete t;
			t = temp;
			temp = temp->next;
		}
		delete t;
	} else {
		std::cerr << "Must be positive" << std::endl;
	}
}
