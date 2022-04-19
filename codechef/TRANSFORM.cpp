#include <iostream>
using namespace std;

int main() {
	int t, x;
	cin >> t;
	while (t--) {
		cin >> x;
		x %= 3;
		switch (x) {
			case 0:
				cout << "normal" << endl;
				break;
			case 1:
				cout << "huge" << endl;
				break;
			case 2:
				cout << "small" << endl;
				break;
		}
	}
	return 0;
}
