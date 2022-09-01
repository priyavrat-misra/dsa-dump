#include <iostream>
#include <stack>
using namespace std;

void push_to_bottom(stack<int>& s, int n, int& val) {
	if (n == 0) { // same as s.empty() but without function calls => faster
		s.push(val);
		return;
	}
	
	int temp = s.top();
	s.pop();
	push_to_bottom(s, n - 1, val);
	s.push(temp);
}

void reverse(stack<int>& s, int n) {
	if (n == 1) // s.size() == 1
		return;
	
	int temp = s.top();
	s.pop();
	reverse(s, n - 1);
	push_to_bottom(s, n - 1, temp);
}

int main() {
	int n;
	if (cin >> n && n > 0) {
		stack<int> s;
		for (int i = 0; i < n; ++i) {
			int e;
			cin >> e;
			s.push(e);
		}
		reverse(s, n);
		while (n--) { // !s.empty()
			cout << " " << s.top();
			s.pop();
		}
		cout << endl;
	} else {
		cerr << "Invalid size." << endl;
	}
}
