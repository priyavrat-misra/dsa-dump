#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int *a = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	priority_queue<int, vector<int>, greater<int>> minH;
	for (int i = 0; i < n; ++i) {
		minH.push(a[i]);
		if (minH.size() > k)
			minH.pop();
	}
	cout << k << " largest elements:";
	while (!minH.empty()) {
		cout << " " << minH.top();
		minH.pop();
	}
	cout << endl;
	delete[] a;
}
