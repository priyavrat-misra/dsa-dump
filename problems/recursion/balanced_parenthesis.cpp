#include <iostream>
#include <string>
using namespace std;

void balancedP(int open, int close, string& op) {
	if (open == 0 && close == 0) {
		cout << " " << op;
		return;
	}
	if (open != 0) {
		string op1 = op;
		op1.push_back('(');
		balancedP(open - 1, close, op1);
	}
	if (close > open) {
		string op2 = op;
		op2.push_back(')');
		balancedP(open, close - 1, op2);
	}
}

int main(int argc, char* argv[]) {
	if (argc == 2) {
		int n = atoi(argv[1]);
		string op;
		balancedP(n, n, op);
		cout << endl;
	} else {
		cerr << "Invalid input." << endl;
	}
}
