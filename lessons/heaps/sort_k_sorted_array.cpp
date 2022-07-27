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
		if (minH.size() > k) {
			a[i-k] = minH.top();
			minH.pop();
		}
	}
	int i = n - k;
	while (!minH.empty()) {
		a[i] = minH.top();
		minH.pop();
		++i;
	}
	cout << "Sorted array:";
	for (int i = 0; i < n; ++i)
		cout << " " << a[i];
	cout << endl;
	delete[] a;
}
