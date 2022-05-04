#include <iostream>
using namespace std;

int main() {
	int t, n, a, i, o;
	cin >> t;
	while (t--) {
		o = 0;
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> a;
			o += a;
		}
		cout << (n - o > o ? 0 : 1) << endl;
	}
}
