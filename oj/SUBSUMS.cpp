// https://www.spoj.com/problems/SUBSUMS/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void genSubsetSum(int start, int size, vector<int>& v, vector<int>& res) {
	for (int mask = 0; mask < (1 << size); ++mask) {
		long long sum = 0;
		for (int i = 0; i < size; ++i)
			if (mask & (1 << i))
				sum += v[start+i];

		res.push_back(sum);
	}
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	
	vector<int> A, B;
	genSubsetSum(0, n/2, v, A);
	genSubsetSum(n/2, n - n/2, v, B);
	sort(B.begin(), B.end());

	// a <= A[i] + B[j] <= b
	// ==> B[j] >= a - A[i]
	// ==> B[j] <= b - A[i]
	long long ans = 0;
	for (int& e : A) {
		long long li = lower_bound(B.begin(), B.end(), a - e) - B.begin();
		long long ri = upper_bound(B.begin(), B.end(), b - e) - B.begin();
		ans += (ri - li);
	}
	cout << ans << endl;
}
