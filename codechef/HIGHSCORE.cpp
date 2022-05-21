#include <iostream>
using namespace std;

int main() {
	int t, n, m, a;
	cin >> t;
	while (t--) {
		cin >> n;
		m = n;
		for (int i = 0; i < 4; ++i) {
			cin >> a;
			if (n - a < m)
			    m = n - a;
		}
		cout << n - m << endl;
	}
}
