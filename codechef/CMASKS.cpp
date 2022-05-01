#include <iostream>
using namespace std;

int main() {
	int t, x, y;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		if (x*100 < y*10)
			cout << "DISPOSABLE" << endl;
		else
			cout << "CLOTH" << endl;
	}
	return 0;
}
