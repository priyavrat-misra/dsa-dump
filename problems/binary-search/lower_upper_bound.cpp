#include <iostream>
using namespace std;

int* bound(int* a, int& n, int& target, bool (*cmp)(int&, int&)) {
	int lo = 0, hi = n;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (cmp(a[mid], target))
			lo = mid + 1;
		else
			hi = mid;
	}
	return a + hi;
}

int main() {
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int target;
	cout << "Enter target: ";
	cin >> target;
	cout << "lower_bound(" << target << "): "
		<< bound(a, n, target, [](int& x, int& y) {return x < y;}) - a
		<< endl;
	cout << "upper_bound(" << target << "): "
		<< bound(a, n, target, [](int& x, int& y) {return x <= y;}) - a
		<< endl;

	delete[] a;
}
