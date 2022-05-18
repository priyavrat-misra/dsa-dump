#include <iostream>
using namespace std;

int main() {
	int n, t, start, ltime;
	cin >> t;
	string c;
	while (t--) {
		cin >> n;
		start = ltime = 0;
		while (n--) {
			cin >> c;
			c == "START38" ? ++start : ++ltime;
		}
		cout << start << " " << ltime << endl;
	}
}
