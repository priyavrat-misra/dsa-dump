#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	int T1, T2, d;
	while (t--) {
		cin >> T1 >> T2;
		d = (T1 < T2 ? T1 - (T2 - T1) : T2);
		cout << d << endl;
	}
	return 0;
}
