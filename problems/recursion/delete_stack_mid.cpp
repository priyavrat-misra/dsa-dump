#include <iostream>
#include <stack>
using namespace std;

void del_mid(stack<int>& s, int k) {
	if (k == 0) {
		s.pop();
		return;
	}

	int val = s.top();
	s.pop();
	del_mid(s, k - 1);
	s.push(val);
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
		del_mid(s, n/2);
		while (--n) { // !s.empty()
			cout << " " << s.top();
			s.pop();
		}
		cout << endl;
	} else {
		cerr << "Invalid size." << endl;
	}
}
