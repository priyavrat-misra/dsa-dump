#include <iostream>
#include <cmath>
using namespace std;

int minDiff(int* a, int& n, int& target) {
	int lo = 0, hi = n - 1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (a[mid] < target)
			lo = mid + 1;
		else if (a[mid] > target)
			hi = mid - 1;
		else
			return a[mid];
	}
	if (lo == n)
		return a[n-1];
	if (hi == -1)
		return a[0];

	int l = abs(a[hi] - target), r = abs(a[lo] - target);
	return l > r ? a[lo] : a[hi];
}

int main() {
	int target, n;
	cin >> target;
	if (cin >> n && n > 0) {
		int* a = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		cout << minDiff(a, n, target) << endl;
		delete[] a;
	} else {
		cout << "Invalid size." << endl;
	}
}
