#include <iostream>
using namespace std;

int main() {
	int t, x, y;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		cout << (x < y ? y - x : x - y) << endl;
	}
	return 0;
}
