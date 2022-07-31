#include <iostream>
#include <vector>
using namespace std;

int num_rotates(vector<int>& v, int& n) {
	int lo = 0, hi = n - 1;
	while (lo <= hi) {
		if (v[lo] < v[hi])
			return (n - lo) % n;
		int mid = lo + (hi - lo) / 2;
		int prev = (mid + n - 1) % n;
		int next = (mid + 1) % n;
		if (v[mid] < v[prev] && v[mid] < v[next])
			return n - mid;
		if (v[lo] > v[mid])
			hi = mid - 1;
		else if (v[mid] > v[hi])
			lo = mid + 1;
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	
	cout << num_rotates(v, n) << endl;
}
