#include <iostream>
using namespace std;

int main() {
	int t, n, a1, a2, c;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 1) {
		    cin >> a1;
		    cout << 1 << endl;
		    continue;
		}
		c = 1;
		cin >> a1 >> a2;
		if (a1 != a2)
			++c;
		n -= 2;
		while (n--) {
			cin >> a1;
			if (a1 != a2) {
				++c;
			    a2 = a1;
			}
		}
		cout << c << endl;
	}
}
