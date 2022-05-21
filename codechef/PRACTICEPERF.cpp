#include <iostream>
using namespace std;

int main() {
	int p, c = 0;
	for (int i = 0; i < 4; ++i) {
		cin >> p;
		if (p < 10)
			continue;
		else
			++c;
	}
	cout << c << endl;
}
