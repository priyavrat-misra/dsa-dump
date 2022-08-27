#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int res = -1;
	int lo = 0, hi = n - 1, mid;
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;
		if (k < a[mid])
			hi = mid - 1;
		else if (k > a[mid])
			lo = mid + 1;
		else {
			res = mid;
			lo = mid + 1;
		}
	}
	cout << res << endl;
}
