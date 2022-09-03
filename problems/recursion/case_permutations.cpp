#include <iostream>
#include <string>
using namespace std;

void casePerm(string& op, string ip) {
	if (ip.empty()) {
		cout << " " << op;
		return;
	}
	string s1 = op, s2 = op;
	s1.push_back(ip.front());
	s2.push_back(ip.front() ^ ' ');
	ip.erase(ip.begin());
	casePerm(s1, ip);
	casePerm(s2, ip);
}

int main() {
	string ip, op;
	cin >> ip;
	casePerm(op, ip);
	cout << endl;
}
