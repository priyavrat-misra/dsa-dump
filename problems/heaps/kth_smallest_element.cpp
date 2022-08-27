#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int *a = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	priority_queue<int> maxH;
	for (int i = 0; i < n; ++i) {
		maxH.push(a[i]);
		if (maxH.size() > k)
			maxH.pop();
	}
	cout << maxH.top() << endl;
	delete[] a;
}
