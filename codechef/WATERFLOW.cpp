#include <iostream>
using namespace std;

int main() {
	int t, w, x, y, z;
	cin >> t;
	while (t--) {
		cin >> w >> x >> y >> z;
		if (w + y * z < x)
			cout << "unfilled" << endl;
		else if (w + y * z > x)
			cout << "overflow" << endl;
		else
			cout << "filled" << endl;
	}
}
