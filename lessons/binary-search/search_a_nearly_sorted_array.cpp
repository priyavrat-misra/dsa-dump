// Note: The elements in the array can be in
// their correct position or one position away.
#include <iostream>
using namespace std;

int binarySearch(int* a, int& n, int& target) {
	int lo = 0, hi = n - 1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (a[mid] == target)
			return mid;
		if (mid - 1 >= lo && a[mid-1] == target)
			return mid - 1;
		if (mid + 1 <= hi && a[mid+1] == target)
			return mid + 1;
		if (a[mid] < target)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return -1;
}

int main() {
	int target, n;
	cin >> target;
	if (cin >> n && n > 0) {
		int* a = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		cout << binarySearch(a, n, target) << endl;
		delete[] a;
	} else {
		cerr << "Invalid size." << endl;
	}
}
