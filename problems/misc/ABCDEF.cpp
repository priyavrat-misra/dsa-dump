// https://www.spoj.com/problems/ABCDEF/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	
	vector<int> lhs, rhs;
	for (int a = 0; a < n; ++a)
		for (int b = 0; b < n; ++b)
			for (int c = 0; c < n; ++c)
				lhs.push_back(v[a]*v[b]+v[c]);

	for (int f = 0; f < n; ++f)
		for (int e = 0; e < n; ++e)
			for (int d = 0; d < n; ++d) {
				if (v[d] == 0)
					continue;
				rhs.push_back((v[f]+v[e])*v[d]);
			}

	sort(rhs.begin(), rhs.end());

	int ans = 0;
	for (int i = 0; i < lhs.size(); ++i) {
		int li = lower_bound(rhs.begin(), rhs.end(), lhs[i]) - rhs.begin();
		int ri = upper_bound(rhs.begin(), rhs.end(), lhs[i]) - rhs.begin();
		ans += (ri - li);
	}
	cout << ans << endl;
}
