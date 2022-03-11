// queue implementation using linked list
#include <iostream>

struct Node {
	int data;
	Node* next;
};

bool isEmpty(Node *front, Node *rear) {
	return front == NULL && rear == NULL;
}

void enqueue(Node **front, Node **rear, int& e) {
	Node *t = new Node;
	t->data = e;
	t->next = NULL;
	if (isEmpty(*front, *rear)) {
		*front = *rear = t;
	} else {
		(*rear)->next = t;
		*rear = t;
	}
}

void dequeue(Node **front, Node **rear) {
	Node *t = *front;
	if (isEmpty(*front, *rear))
		std::cerr << "Queue is empty.";
	else if (*front == *rear) {
		*front = *rear = NULL;
		delete t;
	} else {
		*front = (*front)->next;
		delete t;
	}
}

void print(Node *head) {
	if (head) {
		std::cout << head->data << "<--";
		print(head->next);
	}
}

void del_q(Node *head) {
	if (head) {
		del_q(head->next);
		delete head;
	}
}

int main () {
	int choice = 0, e;
	Node *front, *rear;
	front = rear = NULL;
	while (choice != 3) {
		std::cout << std::endl
			<< "1. Enqueue an element\n"
			<< "2. Dequeue an element\n"
			<< "3. Exit\n"
			<< "Choose one (1, 2 or 3): ";
		std::cin >> choice;
		switch (choice) {
			case 1:
				std::cout << "Enter an element to enqueue: ";
				std::cin >> e;
				enqueue(&front, &rear, e);
				print(front);
				std::cout << std::endl;
				break;
			case 2:
				dequeue(&front, &rear);
				print(front);
				std::cout << std::endl;
				break;
			case 3:
				del_q(front);
				break;
			default:
				std::cerr << "Not a valid choice. Try again."
					<< std::endl;
				break;
		}
	}
}
