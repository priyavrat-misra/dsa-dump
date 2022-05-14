#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << s.size() << "\t" <<
		s.capacity() << endl;
	for (int i = 0; i < 16; ++i) {
		s.push_back(i + 60);  // ascii value
		cout << s.size() << "\t" <<
			s.capacity() << endl;
	}
	cout << s << endl;

	string s1 = "abc";
	string s2("abc");
	string s3(s1);
	string s4(3, 'A');  // or s4(3, 65);
	s1.swap(s4);
	string s5 = string(3, 97) + "123";
	cout << (s5 += 'a') << endl;
	s5.pop_back();
	cout << s5 << endl;
}
