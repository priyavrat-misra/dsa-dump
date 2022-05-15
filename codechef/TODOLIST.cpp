#include <iostream>
using namespace std;

int main() {
	int t, n, d, i = 0;
	cin >> t;
	while (t--) {
		cin >> n;
		while (n--) {
			cin >> d;
			if (d > 999)
				++i;
		}
		cout << i << endl;
		i = 0;
	}
}
