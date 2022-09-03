#include <iostream>
#include <string>
using namespace std;

void solve(int n, string& op, int o = 0, int z = 0) {
	if (n == 0) {
		cout << " " << op;
		return;
	}
	string op1 = op;
	op1.push_back('1');
	solve(n - 1, op1, o + 1, z);
	if (o > z) {
		string op2 = op;
		op2.push_back('0');
		solve(n - 1, op2, o, z + 1);
	}
}

int main(int argc, char* argv[]) {
	if (argc == 2) {
		int n = atoi(argv[1]);
		string op;
		solve(n, op);
		cout << endl;
	} else {
		cerr << "Invalid input." << endl;
	}
}
