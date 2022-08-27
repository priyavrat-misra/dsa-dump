// https://www.codechef.com/problems/LGCD
/**
 * we know, a * b = LCM(a, b) * GCD(a, b)
 * => a * b = 2 * GCD(a, b) * GCD(a, b) --- (1)
 * a = c1 * GCD(a, b) --------------------- (2)
 * b = c2 * GCD(a, b) --------------------- (3)
 * from (1), (2), (3), c1 * c2 = 2
 * => c1 = 1, c2 = 2 or c1 = 2, c2 = 1
 * (2)/(3) => a/b = c1/c2
 * => a/b = 1/2 => 2a = b
 * or a/b = 2/1 => a = 2b
 * => to find # pairs with (x, 2x)
 */

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	if (cin >> n && n > 0) {
		unordered_map<int, int> freq;
		while (n--) {
			int e;
			cin >> e;
			++freq[e];
		}
		int ans = 0;
		for (auto& row : freq)
			if (freq.count(row.first * 2))
				ans += row.second * freq[row.first * 2];

		cout << ans << endl;
	} else {
		cerr << "Invalid size." << endl;
	}
}
