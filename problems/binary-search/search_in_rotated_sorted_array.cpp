#include <iostream>
using namespace std;

int binarySearch(int* a, int lo, int hi, int& target) {
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (a[mid] > target)
			hi = mid - 1;
		else if (a[mid] < target)
			lo = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main() {
	int target, n;
	cin >> target >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	// search index of min element
	int lo = 0, hi = n - 1, mid;
	while (lo <= hi) {
		if (a[lo] < a[hi]) {
			mid = lo;
			break;
		}

		mid = lo + (hi - lo) / 2;
		int prev = (mid + n - 1) % n, next = (mid + 1) % n;
		if (a[mid] < a[prev] && a[mid] < a[next])
			break;
		if (a[mid] < a[lo])
			hi = mid - 1;
		else if (a[mid] > a[hi])
			lo = mid + 1;

	}

	// binary search on the advantageous half
	if (target > a[n-1])
		cout << binarySearch(a, 0, mid - 1, target);
	else
		cout << binarySearch(a, mid, n - 1, target);
	
	cout << endl;
	delete[] a;
}
