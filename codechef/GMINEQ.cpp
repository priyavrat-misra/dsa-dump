#include <iostream>
using namespace std;

int main() {
	int t, n, x, y, v;
	cin >> t;
	while (t--) {
		x = y = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> v;
			if (v == 1)
				++x;
			else
				++y;
		}
		v = (x > y ? x - y : y - x);
		if (v < 2)
			cout << "Yes" << endl;
		else if (v == 2) {
			if (x % 2)
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
		} else
			cout << "No" << endl;
	}
	return 0;
}
