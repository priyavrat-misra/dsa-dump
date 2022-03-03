#include <iostream>
#define QSIZE 10

bool isEmpty(int& front, int& rear) {
	return front == -1 && rear == -1;
}

bool enqueue(int* Q, int& e, int& front, int& rear) {
	if (isEmpty(front, rear)) {
		rear = front = 0;
		Q[rear] = e;
		return true;
	} else if ((rear + 1) % QSIZE == front) {
		return false;
	} else {
		rear = (rear + 1) % QSIZE;
		Q[rear] = e;
		return true;
	}
}

bool dequeue(int& front, int& rear) {
	if (isEmpty(front, rear))
		return false;
	else if (front == rear) {
		front = rear = -1;
		return false;
	} else {
		front = (front + 1) % QSIZE;
		return true;
	}
}

void print(int* Q, int front, int rear) {
	if (isEmpty(front, rear))
		return;

	std::cout << "-->" << Q[front];
	while (rear != front) {
		front = (front + 1) % QSIZE;
		std::cout << "-->" << Q[front];
	}
	std::cout << std::endl;
}

int main () {
	int choice = 0, e, front, rear, Q[QSIZE];
	front = rear = -1;
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
				if (!enqueue(Q, e, front, rear))
					std::cerr << "Queue is full." << std::endl;
				print(Q, front, rear);
				break;
			case 2:
				if (!dequeue(front, rear))
					std::cerr << "Queue is empty." << std::endl;
				else
					print(Q, front, rear);
				break;
			case 3:
				break;
			default:
				std::cerr << "Not a valid choice. Try again."
					<< std::endl;
				break;
		}
	}
}
