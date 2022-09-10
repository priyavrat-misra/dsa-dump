// check if the given sum can be found from any subsets
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, sum;
	cin >> n >> sum;
	int* set = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> set[i];

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
	cout << dp[n][sum] << endl;
	delete[] set;
}
