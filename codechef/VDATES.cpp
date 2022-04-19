#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int D, L, R;
	while (t--) {
		cin >> D >> L >> R;
		if (D < L)
			cout << "Too Early" << endl;
		else if (D > R)
			cout << "Too Late" << endl;
		else
			cout << "Take second dose now" << endl;
	}
	return 0;
}
