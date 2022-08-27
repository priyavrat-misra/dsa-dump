// https://codeforces.com/problemset/problem/276/C
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int l, r;
	vector<int> diffv(n);
	while (q--) {
		cin >> l >> r;
		++diffv[--l];
		if (r < n)
			--diffv[r];
	}
	for (int i = 1; i < n; ++i)
		diffv[i] += diffv[i-1];

	sort(v.begin(), v.end());
	sort(diffv.begin(), diffv.end());

	long long ans = 0;
	for (int i = 0; i < n; ++i)
		ans += v[i] * diffv[i];

	cout << ans << endl;
}
