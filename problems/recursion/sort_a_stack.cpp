#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int>& s, int& temp) {
	if (s.empty() || s.top() <= temp) {
		s.push(temp);
		return;
	}
	int val = s.top();
	s.pop();
	insert(s, temp);
	s.push(val);
}

void sort(stack<int>& s, int n) {
	if (n == 1) // s.size() == 1
		return;

	int temp = s.top();
	s.pop();
	sort(s, n - 1);
	insert(s, temp);
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
		sort(s, n);
		while (n--) { // !s.empty()
			cout << " " << s.top();
			s.pop();
		}
		cout << endl;
	} else {
		cerr << "Invalid size." << endl;
	}
}
