#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> points(n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		points[i] = {x, y};
	}
	priority_queue<pair<double, pair<int, int>>> maxH;
	for (auto& point : points) {
		maxH.push({point.first * point.first + point.second * point.second, point});
		if (maxH.size() > k)
			maxH.pop();
	}
	cout << k << " closest points to origin are:";
	while (!maxH.empty()) {
		cout << " (" << maxH.top().second.first << ", " << maxH.top().second.second << ")";
		maxH.pop();
	}
	cout << endl;
}
