#include <iostream>
using namespace std;

int main() {
	int t, x, y;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		cout << (x*3 < y*2 ? x*3 : y*2) << endl;
	}
	return 0;
}
