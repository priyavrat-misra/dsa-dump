#include <iostream>
using namespace std;

int main() {
	int t, x;
	cin >> t;
	while (t--) {
		cin >> x;
		cout << (x*0.1 < 100 ? 100 : x*0.1) << endl;
	}
	return 0;
}
