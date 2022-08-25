#include <iostream>
using namespace std;

int peak(int* a, int& n) {
	int lo = 0, hi = n - 1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (mid > 0 && mid < n - 1) {
			if (a[mid] > a[mid-1] && a[mid] > a[mid+1])
				return mid;
			else if (a[mid] < a[mid-1])
				hi = mid - 1;
			else if (a[mid] < a[mid+1])
				lo = mid + 1;
		} else if (mid == 0) {
			return a[0] > a[1] ? 0 : 1;
		} else if (mid == n - 1) {
			return a[n-1] > a[n-2] ? n - 1 : n - 2;
		}
	}
	return -1;
}

int main() {
	int n;
	if (cin >> n && n > 0) {
		int* a = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		cout << peak(a, n) << endl;
		delete[] a;
	} else {
		cerr << "Invalid size." << endl;
	}
}
