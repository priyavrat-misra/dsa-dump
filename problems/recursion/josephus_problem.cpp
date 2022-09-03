#include <iostream>
#include <vector>
using namespace std;

void solve(vector<bool>& circ, int& n, int& cnt, int& k, int& sword) {
	if (cnt == 1)
		return;

	int i = 0;
	while (i < k) {
		if (circ[sword])
			++i;
		sword = (sword + 1) % n;
	}
	while (!circ[sword])
		sword = (sword + 1) % n;

	circ[sword] = false;
	--cnt;
	solve(circ, n, cnt, k, sword);
}

int main(int argc, char* argv[]) {
	if (argc == 3) {
		int n = atoi(argv[1]), k = atoi(argv[2]);
		vector<bool> circ(n, true);
		--k;
		int sword = 0, cnt = n, i = 0;
		solve(circ, n, cnt, k, sword);
		while (!circ[i])
			++i;
		cout << i + 1 << endl; // last man standing
	} else {
		cerr << "Invalid input." << endl;
	}
}
