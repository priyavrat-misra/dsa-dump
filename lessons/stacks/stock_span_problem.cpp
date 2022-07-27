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

	stack<pair<int, int>> s;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		while (!s.empty() && s.top().first < arr[i])
			s.pop();

		if (s.empty())
			ans.push_back(-1);
		else
			ans.push_back(s.top().second);

		s.push({arr[i], i});
	}
	cout << "Stock Span:";
	for (int i = 0; i < n; ++i) {
		ans[i] = i - ans[i];
		cout << " " << ans[i];
	}
	cout << endl;
}
