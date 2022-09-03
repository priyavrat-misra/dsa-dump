#include <iostream>
#include <string>
using namespace std;

void subseq(string& op, string ip) {
	if (ip.empty()) {
		cout << " " << op;
		return;
	}
	string s1 = op, s2 = op;
	s1.push_back('_');
	s1.push_back(ip.front());
	s2.push_back(ip.front());
	ip.erase(ip.begin());
	subseq(s1, ip);
	subseq(s2, ip);
}

int main() {
	string ip, op;
	cin >> ip;
	op.push_back(ip.front());
	ip.erase(ip.begin());
	subseq(op, ip);
	cout << endl;
}
