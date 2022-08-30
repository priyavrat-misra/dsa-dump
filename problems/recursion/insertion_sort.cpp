#include <iostream>
using namespace std;

void insert(int* a, int n, int& temp) {
	if (n == 0 || a[n-1] <= temp) {
		a[n] = temp;
		return;
	}
	int val = a[n-1];
	insert(a, n - 1, temp);
	a[n] = val;
}

void sort(int* a, int n) {
	if (n == 1)
		return;
	
	int temp = a[n-1];
	sort(a, n - 1);
	insert(a, n - 1, temp);
}

int main() {
	int n;
	if (cin >> n && n > 0) {
		int* a = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		sort(a, n);
		for (int i = 0; i < n; ++i)
			cout << " " << a[i];

		cout << endl;
		delete[] a;
	} else {
		cerr << "Invalid size." << endl;
	}
}
