#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	cin >> n;
	unordered_map<int, int> m;
	while (n--) {
		int e;
		cin >> e;
		++m[e];
	}
	priority_queue<pair<int, int>> maxH;
	for (auto& row : m)
		maxH.push({row.second, row.first});

	cout << "Sorted by frequencies:";
	while (!maxH.empty()) {
		for (int i = 0; i < maxH.top().first; ++i)
			cout << " " << maxH.top().second;
		maxH.pop();
	}
	cout << endl;
}
