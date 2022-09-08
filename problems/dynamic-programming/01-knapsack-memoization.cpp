#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int knapsack(int*& weights, int*& profits, int capacity, int n, vector<vector<int>>& dp) {
	if (capacity == 0 || n == 0)
		return 0;
	
	if (dp[n-1][capacity-1] != -1)
		return dp[n-1][capacity-1];

	if (weights[n-1] > capacity)
		return dp[n-1][capacity-1] = knapsack(weights, profits, capacity, n - 1, dp);
	else
		return dp[n-1][capacity-1]
			= max(
				profits[n-1] + knapsack(weights, profits, capacity - weights[n-1], n - 1, dp),
				knapsack(weights, profits, capacity, n - 1, dp)
			);
}

int main() {
	int n, capacity;
	cin >> n >> capacity;
	int* weights = new int[n];
	int* profits = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> weights[i] >> profits[i];

	vector<vector<int>> dp(n, vector<int>(capacity, -1));
	cout << knapsack(weights, profits, capacity, n, dp) << endl;

	delete[] weights;
	delete[] profits;
}
