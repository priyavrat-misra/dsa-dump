#include <iostream>
using namespace std;

int main() {
	int t, n, i, a;
	cin >> t;
	while (t--) {
		cin >> n;
		int l[10]{0}, m = 0, c = 1;
		for (i = 0; i < n; ++i) {
			cin >> a;
			++l[a - 1];
		}
		for (i = 1; i < 10; ++i)
			if (l[m] < l[i])
				m = i;
		
		for (i = m + 1; i < 10; ++i) {
			if (l[m] == l[i]) {
				cout << "confused" << endl;
				c = 0;
				break;
			}
		}
		if (c)
			cout << m + 1 << endl;
	}
}
