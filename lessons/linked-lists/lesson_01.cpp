// linked list with a single node
struct Node {
	int data;
	Node *next;
};

int main() {
	Node *start = 0;  // to hold the address of the LL
	Node *temp = new Node;  // `Node()` also works 
	temp->data = 1; // same as (*temp).data = 1;
	temp->next = 0;  // or `nullptr` or `NULL`
	
	head = temp;
	
	delete temp;
}
