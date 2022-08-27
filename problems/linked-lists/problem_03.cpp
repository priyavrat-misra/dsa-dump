// reverse a linked list - iterative solution
// time complexity: O(n)
// space complexity: O(n) - explicit stack
#include <iostream>
#include <stack>

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
	if (head == NULL) return;
	std::stack<Node*> st;
	Node* t = *head;
	while (t) {
		st.push(t);
		t = t->next;
	}
	*head = t = st.top();
	st.pop();
	while (!st.empty()) {
		t->next = st.top();
		st.pop();
		t = t->next;
	}
	t->next = NULL;
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
