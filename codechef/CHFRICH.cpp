#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	int A, B, X;
	while (t--) {
		cin >> A >> B >> X;
		cout << (B - A) / X << endl;
	}
	return 0;
}
