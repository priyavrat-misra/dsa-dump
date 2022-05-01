#include <iostream>
using namespace std;

int main() {
	int t, x, y, z;
	cin >> t;
	while (t--) {
		cin >> x >> y >> z;
		if (x + y > z) {
			if (x > z)
				cout << 0 << endl;
			else
				cout << 1 << endl;
		} else {
			cout << 2 << endl;
		}
	}
	return 0;
}
