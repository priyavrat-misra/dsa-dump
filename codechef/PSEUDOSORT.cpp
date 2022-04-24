#include <iostream>
using namespace std;

bool swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
	return true;
}

bool nondec(int* a, int& n) {
	for (int i = 1; i < n; i++)
		if (a[i-1] > a[i])
			return false;
	return true;
}

int main() {
	int t, n, a[100000];
	cin >> t;
	while (t--) {
		cin >> n;
		int s = 0, i = 0;

		for (; i < n; ++i)
			cin >> a[i];
		
		i = 1;
		while (s < 2 && i < n) {
			if (a[i-1] > a[i])
				s += swap(a[i-1], a[i]);
			++i;
		}

		if (s < 2 && nondec(a, n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
