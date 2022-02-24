#include <iostream>

struct Node {
	int data;
	Node* next;
};

void print(Node* head) {
	if (head) {
		std::cout << "-->" << head->data;
		print(head->next);
	}
}

void insert(Node** head, int& e, const int& pos, int& s) {
	Node* t1 = new Node;
	t1->data = e;
	if (pos == 0) {
		t1->next = *head;
		*head = t1;
	} else {
		Node* t2 = *head;
		for (int i = 0; i < pos - 1; ++i)
			t2 = t2->next;
		t1->next = t2->next;
		t2->next = t1;
	}
	++s;
}

void del_node(Node** head, const int& pos, int& s) {
	Node* t1 = *head;
	if (pos == 0) {
		*head = (*head)->next;
		delete t1;
	} else {
		for(int i = 0; i < pos - 1; ++i)
			t1 = t1->next;
		Node* t2 = t1->next;
		t1->next = t1->next->next;
		delete t2;
	}
	--s;
}

void del_list(Node* head) {
	if (head) {
		del_list(head->next);
		delete head;
	}
}

void reverse(Node* t, Node** head) {
	if (t->next == NULL) {
		*head = t;
		return;
	}
	reverse(t->next, head);
	Node* s = t->next;
	s->next = t;
	t->next = NULL;
}

int main() {
	int choice = 0, e, pos, s = 0;
	Node* head = NULL;
	while (choice != 4) {
		std::cout
			<< "0. Insert a node\n"
			<< "1. Delete a node\n"
			<< "2. Print the linked list\n"
			<< "3. Reverse the linked list\n"
			<< "4. Delete the linked list & exit\n"
			<< "Choose one (0, 1, 2, 3 or 4): ";
		std::cin >> choice;
		switch (choice) {
			case 0:
				std::cout << "Enter an element to insert: ";
				std::cin >> e;
				std::cout << "Enter a position to insert it: ";
				while (!(std::cin >> pos && pos >= 0 && pos <= s))
					std::cerr << "Not a valid position, enter again: ";
				insert(&head, e, pos, s);
				std::cout << std::endl;
				break;
			case 1:
				if (s == 0) {
					std::cout << "Nothing to delete. Insert first.\n\n";
					break;	
				}
				std::cout << "Enter position of the element to delete: ";
				while (!(std::cin >> pos && pos >= 0 && pos < s))
					std::cerr << "Not a valid position, enter again: ";
				del_node(&head, pos, s);
				std::cout << std::endl;
				break;
			case 2:
				std::cout << "The linked list: ";
				print(head);
				std::cout << "\n\n";
				break;
			case 3:
				if (s == 0) {
					std::cerr << "Nothing to reverse. Insert first.\n\n";
					break;	
				}
				reverse(head, &head);
				std::cout << std::endl;
				break;
			case 4:
				del_list(head);
				break;
			default:
				std::cerr << "Not a valid choice, try again.\n\n";
				break;
		}
	}
}
