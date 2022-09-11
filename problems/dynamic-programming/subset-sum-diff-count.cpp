// count the number of subset pairs with a given difference
// exactly same to https://leetcode.com/problems/target-sum
#include <iostream>
#include <vector>
using namespace std;

int countSubsets(int*& set, int& n, int sum) {
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
	return dp[n][sum];
}

int main() {
	int n, diff;
	cin >> n >> diff;
	int* set = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> set[i];

	// to find sum(s1) - sum(s2) = diff
	// given, sum(s1) + sum(s2) = total
	// => sum(s1) = (total + diff) / 2
	int total = 0;
	for (int i = 0; i < n; ++i)
		total += set[i];

	cout << countSubsets(set, n, (total + diff) / 2) << endl;
	delete[] set;
}
