#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int t, m, n;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<pair<long long, int>> v(n);  // n boxes
		for (int i = 0; i < n; ++i) {
			cin >> v[i].first;  // no of balls
			v[i].second = i%m;  // color of the box
		}
		sort(v.begin(), v.end());
		vector<int> freq(m, 0);
		long long min = LLONG_MAX;
		int count = m, right = 0;
		for (int left = 0; left < n; ++left) {
			while (right < n and count) {
				count -= freq[v[right].second] == 0;
				++freq[v[right].second];
				++right;
			}
			if (count == 0)
				min = std::min(min, v[right-1].first - v[left].first);

			if (freq[v[left].second])
				--freq[v[left].second];

			count += freq[v[left].second] == 0;
		}
		cout << min << endl;
	}
}
