#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> height(n);
	for (int i = 0; i < n; ++i)
		cin >> height[i];

	vector<int> nsl, nsr;
	stack<pair<int, int>> s;

	for (int i = 0; i < n; ++i) {
		while (!s.empty() && s.top().first >= height[i])
			s.pop();
		if (s.empty())
			nsl.push_back(-1);
		else
			nsl.push_back(s.top().second);

		s.push({height[i], i});
	}

	while (!s.empty())
		s.pop();

	for (int i = n - 1; i >= 0; --i) {
		while (!s.empty() && s.top().first >= height[i])
			s.pop();
		if (s.empty())
			nsr.push_back(n);
		else
			nsr.push_back(s.top().second);

		s.push({height[i], i});
	}

	reverse(nsr.begin(), nsr.end());

	vector<int> width(n);
	for (int i = 0; i < n; ++i)
		width[i] = nsr[i] - nsl[i] - 1;

	int max_area = 0;
	for (int i = 0; i < n; ++i)
		max_area = max(max_area, height[i] * width[i]);

	cout << max_area << endl;
}
