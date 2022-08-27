#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int k = k1 > k2 ? k1 : k2;
	priority_queue<int> maxH;
	for (int i = 0; i < n; ++i) {
		maxH.push(a[i]);
		if (maxH.size() >= k)
			maxH.pop();
	}
	int sum = 0;
	for (int i = 1; i < abs(k2 - k1); ++i) {
		sum += maxH.top();
		maxH.pop();
	}
	cout << sum << endl;
}
