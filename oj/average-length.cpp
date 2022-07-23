// https://atcoder.jp/contests/abc145/tasks/abc145_c
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long double> x(n), y(n);
	vector<int> perm(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		perm[i] = i;
	}

	int n_fact = 0;
	long double ans = 0.0;
	do {
		for (int i = 1; i < n; ++i) {
			ans += sqrtl(
					(x[perm[i]] - x[perm[i-1]]) * (x[perm[i]] - x[perm[i-1]])
					+
					(y[perm[i]] - y[perm[i-1]]) * (y[perm[i]] - y[perm[i-1]])
				);
		}
		++n_fact;
	} while (next_permutation(perm.begin(), perm.end()));
	ans /= n_fact;
	cout.precision(9);
	cout << fixed << ans << endl;
}
