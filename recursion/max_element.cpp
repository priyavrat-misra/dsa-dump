#include <iostream>
using namespace std;

int findMax(int *a, const int& n) {
	if (n == 1)
		return *a;

	int mid = n / 2;
	int x = findMax(a, mid);
	int y = findMax(a + mid, n - mid);
	return x < y ? y : x;
}

int main() {
	int n;
	cout << "Enter size of the array: ";
	if (cin >> n && n > 0) {
		int *a = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		cout << findMax(a, n) << endl;
		delete[] a;
	} else {
		cerr << "Size must be at least 1." << endl;
	}
}
