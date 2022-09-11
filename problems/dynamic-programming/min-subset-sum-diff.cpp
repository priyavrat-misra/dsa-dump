#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int minDiff(int*& set, int& n) {
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += set[i];

	vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
	for (int i = 0; i < n + 1; ++i)
		dp[i][0] = true;

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < sum + 1; ++j) {
			if (set[i-1] > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j-set[i-1]] || dp[i-1][j];
		}
	}

	int mn = sum;
	for (int i = 0; i <= sum / 2; ++i)
		if (dp[n][i])
			mn = min(mn, sum - i - i);

	return mn;
}

int main() {
	int n;
	cin >> n;
	int* set = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> set[i];

	cout << minDiff(set, n) << endl;
	delete[] set;
}
