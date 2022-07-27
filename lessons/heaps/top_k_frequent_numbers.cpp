#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int n, k;
	cin >> n >> k;
	unordered_map<int, int> m;
	while (n--) {
		int e;
		cin >> e;
		++m[e];
	}
	priority_queue<pii, vector<pii>, greater<pii>> minH;
	for (auto& row : m) {
		minH.push({row.second, row.first});
		if (minH.size() > k)
			minH.pop();
	}
	cout << "Top " << k << " frequent numbers:";
	while (!minH.empty()) {
		cout << " " << minH.top().second;
		minH.pop();
	}
	cout << endl;
}
