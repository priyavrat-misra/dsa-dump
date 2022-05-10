#include <iostream>
using namespace std;

int rev(int n) {
	int rem, rev = 0;
	while (n > 0) {
		rem = n % 10;
		rev = rev * 10 + rem;
		n /= 10;
	}
	return rev;
}

int main() {
	int n;
	cout << "Enter a positive number: ";
	if (cin >> n && n >= 0) {
		cout << (n == rev(n) ? "It is" : "Not")
			<< " a palindrome number." << endl;
	} else {
		cerr << "Number must be positive." << endl;
	}
}
