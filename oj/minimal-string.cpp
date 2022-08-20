// https://codeforces.com/problemset/problem/797/C
#include <iostream>
#include <stack>
using namespace std;

int main() {
	string s;
	cin >> s;
	int freq[26]{0};
	for (char& c : s)
		++freq[c-'a'];

	stack<char> t;
	string u;
	int ptr = 0;
	while (!freq[ptr] && ptr < 26)
		++ptr;
	for (int i = 0; i < s.size(); ++i) {
		t.push(s[i]);
		--freq[s[i]-'a'];
		while (!freq[ptr] && ptr < 26)
			++ptr;
		while (!t.empty() && t.top() <= 'a' + ptr) {
			u += t.top();
			t.pop();
		}
	}
	cout << u << endl;
}
