#include <iostream>
using namespace std;

bool isMin(int* a, int& n, int& k, int& pivot) {
	int s = 1, sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (sum > pivot)
			++s, sum = a[i];
		
		if (s > k)
			return false;
	}
	return true;
}

int minPages(int* a, int& n, int& k) {
	if (n < k)
		return -1;

	int lo = a[n-1], hi = 0;
	for (int i = 0; i < n; ++i)
		hi += a[i];

	if (k == 1)
		return hi;

	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (isMin(a, n, k, mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	return hi;
}

int main() {
	int k, n;
	if (cin >> k >> n && n > 0 && k > 0) {
		int* a = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		cout << minPages(a, n, k) << endl;
		delete[] a;
	} else {
		cerr << "Invalid size." << endl;
	}
}
