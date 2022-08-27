#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> minH;
	while (n--) {
		int e;
		cin >> e;
		minH.push(e);
	}
	int min_cost = 0;
	while (minH.size() != 1) {
		int first = minH.top();
		minH.pop();
		int second = minH.top();
		minH.pop();
		min_cost += first + second;
		minH.push(first + second);
	}
	cout << min_cost << endl;
}
