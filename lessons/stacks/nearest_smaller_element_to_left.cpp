#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	stack<int> s;
	vector<int> ans;
	vector<int>::iterator it = arr.begin();
	while (it != arr.end()) {
		while (!s.empty() && s.top() > *it)
			s.pop();

		if (!s.empty())
			ans.push_back(s.top());
		else
			ans.push_back(-1);

		s.push(*it);
		++it;
	}
	cout << "NSL:";
	for (int& i : ans)
		cout << " " << i;
	cout << endl;
}
