// https://www.codechef.com/problems/FENCE
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k, x, y;
		int dx[] = {-1, 0, 1, 0};
		int dy[] = {0, -1, 0, 1};
		unordered_map<int, unordered_map<int, bool>> mp;
		int ans = 0;
		cin >> n >> m >> k;
		while (k--) {
			cin >> x >> y;
			for (int i = 0; i < 4; ++i)
				ans += mp[x+dx[i]][y+dy[i]] ? -1 : 1;
			mp[x][y] = 1;
		}
		cout << ans << endl;
	}
}
