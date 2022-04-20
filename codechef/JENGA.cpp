#include <iostream>
using namespace std;

int main() {
	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		cout << (x % n ? "no" : "yes") << endl;
	}
	return 0;
}
