#include <iostream>
using namespace std;

int main() {
	int t, x, y;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		cout << 1500 - 2 * min(3*x+2*y, x+3*y)
			<< endl;
	}
}
