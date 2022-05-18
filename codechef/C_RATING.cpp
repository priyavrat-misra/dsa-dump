#include <iostream>
using namespace std;

int main() {
	int t, x, y, d;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		cout << (d % 8 ? (8 + d) / 8 : d / 8) << endl;
	}
}
