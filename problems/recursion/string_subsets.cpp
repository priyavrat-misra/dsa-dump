#include <iostream>
#include <string>
using namespace std;

void subsets(string& op, string ip) {
	if (ip.empty()) {
		cout << " " << op;
		return;
	}
	string s1 = op;
	string s2 = op;
	s2.push_back(ip.front());
	ip.erase(ip.begin());
	subsets(s1, ip);
	subsets(s2, ip);
}

int main() {
	string ip, op;
	cin >> ip;
	subsets(op, ip);
	cout << endl;
}
