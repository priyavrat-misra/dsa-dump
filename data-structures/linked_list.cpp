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

void insert(Node** head, int& e, const int& pos) {
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
}

void del_node(Node** head, const int& pos) {
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
	t->next->next = t;
	t->next = NULL;
}

int main() {
	int choice = 0, e, pos, size = 0;
	Node* head = NULL;
	while (choice != 5) {
		std::cout << std::endl
			<< "1. Insert a node\n"
			<< "2. Delete a node\n"
			<< "3. Print the linked list\n"
			<< "4. Reverse the linked list\n"
			<< "5. Delete the linked list & exit\n"
			<< "Choose one (1, 2, 3, 4 or 5): ";
		std::cin >> choice;
		switch (choice) {
			case 1:
				std::cout << "Enter an element to insert: ";
				std::cin >> e;
				std::cout << "Enter a position to insert it: ";
				while (!(std::cin >> pos && pos >= 0 && pos <= size))
					std::cerr << "Not a valid position, enter again: ";
				insert(&head, e, pos);
				++size;
				break;
			case 2:
				if (size == 0) {
					std::cout << "Nothing to delete. Insert first.\n";
					break;	
				}
				std::cout << "Enter position of the element to delete: ";
				while (!(std::cin >> pos && pos >= 0 && pos < size))
					std::cerr << "Not a valid position, enter again: ";
				del_node(&head, pos);
				--size;
				break;
			case 3:
				std::cout << "The linked list: ";
				print(head);
				std::cout << std::endl;
				break;
			case 4:
				if (size == 0) {
					std::cerr << "Nothing to reverse. Insert first.\n";
					break;	
				}
				reverse(head, &head);
				break;
			case 5:
				del_list(head);
				break;
			default:
				std::cerr << "Not a valid choice, try again.\n";
				break;
		}
	}
}
