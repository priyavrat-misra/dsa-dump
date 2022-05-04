#include <iostream>
using namespace std;

int main() {
	int t, n, x, a[200], i;
	cin >> t;
	while (t--) {
		int s = 0, m = 0, z = 0, c = 1;
		cin >> n >> x;
		
		for (i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] % x)
				s += (a[i]/x + 1);
			else
				s += a[i]/x;
		}

		while (c) {
			c = 0;
			for (i = 0; i < n; ++i) {
				if (a[i])
					--a[i];
				c += a[i];
			}
			++m;
		}
		cout << (m < s ? m : s) << endl;
	}
}
