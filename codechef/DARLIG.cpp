#include <iostream>
using namespace std;

int main() {
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (k) {
			if (n % 4)
				cout << "Ambiguous" << endl;
			else
				cout << "On" << endl;
		} else {
			if (n % 4)
				cout << "On" << endl;
			else
				cout << "Off" << endl;
		}
	}
	return 0;
}
