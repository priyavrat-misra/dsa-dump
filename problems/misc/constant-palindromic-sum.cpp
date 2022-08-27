// https://codeforces.com/problemset/problem/1343/D
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		vector<int> zero_repl(2*k+1), atmost_one_repl(2*k+1);
		for (int i = 0; i < n / 2; ++i) {
			++zero_repl[v[i] + v[n-i-1]];
			++atmost_one_repl[min(v[i], v[n-i-1]) + 1];
			--atmost_one_repl[max(v[i], v[n-i-1]) + k + 1];
		}
		for (int i = 1; i < 2*k+1; ++i)
			atmost_one_repl[i] += atmost_one_repl[i-1];
		
		int ans = INT_MAX;
		for (int i = 2; i < 2*k; ++i)
			ans = min(ans, 1 * (atmost_one_repl[i] - zero_repl[i]) + 2 * (n/2 - atmost_one_repl[i]));

		cout << ans << endl;
	}
}
