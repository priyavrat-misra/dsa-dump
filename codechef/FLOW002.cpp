#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int a, b;
	while (t--) {
		cin >> a >> b;
		cout << endl << a % b;
	}
	return 0;
}
