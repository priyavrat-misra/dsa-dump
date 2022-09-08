#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(int*& weights, int*& profits, int capacity, int n) {
	if (capacity == 0 || n == 0)
		return 0;
	
	if (weights[n-1] > capacity)
		return knapsack(weights, profits, capacity, n - 1);
	else
		return max(
				profits[n-1] + knapsack(weights, profits, capacity - weights[n-1], n - 1),
				knapsack(weights, profits, capacity, n - 1)
			);
}

int main() {
	int n, capacity;
	cin >> n >> capacity;
	int *weights = new int[n];
	int *profits = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> weights[i] >> profits[i];

	cout << knapsack(weights, profits, capacity, n) << endl;
	
	delete[] weights;
	delete[] profits;
}
