#include <iostream>
using namespace std;

int insPos(int* a, int& n, int& target) {
	int lo = 0, hi = n;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (a[mid] < target)
			lo = mid + 1;
		else
			hi = mid;
	}
	return hi;
}

int main() {
	int target, n;
	cin >> target;
	if (cin >> n && n > 0) {
		int* a = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		int pos = insPos(a, n, target);
		cout << "floor(" << target << "): "
			<< (a[pos] == target ? a[pos] : pos ? a[pos-1] : -1) << endl;
		cout << "ceil(" << target << "): "
			<< (pos == n ? -1 : a[pos]) << endl;
		delete[] a;
	} else {
		cerr << "Invalid size." << endl;
	}
}
