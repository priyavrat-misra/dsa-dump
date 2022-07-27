#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, k, x;
	cin >> n >> k >> x;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	priority_queue<pair<int, int>> maxH;
	for (int i = 0; i < n; ++i) {
		maxH.push({abs(x - v[i]), v[i]});
		if (maxH.size() > k)
			maxH.pop();
	}
	cout << k << " closest numbers to " << x << ":";
	while (!maxH.empty()) {
		cout << " " << maxH.top().second;
		maxH.pop();
	}
	cout << endl;
}
