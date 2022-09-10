// count subsets with given sum
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, sum;
	cin >> n >> sum;
	int* set = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> set[i];

	vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
	int zeroes = 1;
	dp[0][0] = 1;
	for (int i = 1; i < n + 1; ++i) {
		if (set[i-1] == 0)
			zeroes <<= 1;
		
		dp[i][0] = zeroes;
	}

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < sum + 1; ++j) {
			if (set[i-1] > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j-set[i-1]] + dp[i-1][j];
		}
	}

	for (auto& row : dp) {
		for (const auto& v : row)
			cout << " " << v;
		cout << endl;
	}

	cout << dp[n][sum] << endl;
	delete[] set;
}
