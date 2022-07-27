#include <iostream>
using namespace std;

inline int max(int a, int b) {
	return a > b ? a : b;
}

inline int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int n;
	cin >> n;
	int *height = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> height[i];

	int *maxL = new int[n], *maxR = new int[n];
	maxL[0] = height[0];
	for (int i = 1; i < n; ++i)
		maxL[i] = max(height[i], maxL[i-1]);
	
	maxR[n-1] = height[n-1];
	for (int i = n - 2; i >= 0; --i)
		maxR[i] = max(height[i], maxR[i+1]);

	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans += (min(maxL[i], maxR[i]) - height[i]);

	cout << ans << endl;
	delete[] height;
	delete[] maxL;
	delete[] maxR;

}
