#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, capacity;
	cin >> n >> capacity;
	int* weights = new int[n];
	int* profits = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> weights[i] >> profits[i];

	vector<vector<int>> dp(n + 1, vector<int>(capacity + 1));
	for (int i = 1; i < n + 1; ++i)
		for (int j = 1; j < capacity + 1; ++j) {
			if (weights[i-1] > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(
						profits[i-1] + dp[i-1][j-weights[i-1]],
						dp[i-1][j]
					      );
		}
	
	cout << dp[n][capacity] << endl;
	delete[] weights;
	delete[] profits;
}
