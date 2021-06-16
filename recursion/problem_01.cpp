// karatsuba multiplication
#include <iostream>
#include <string>

bool minus(std::string& s) {
	if (s[0] == '-') {
		s.erase(s.begin());
		return true;
	}
	return false;
}

void addzeros(std::string& s1, std::string& s2) {
	if (s1.size() > s2.size())
		s2.insert(0, s1.size() - s2.size(), '0');
	else
		s1.insert(0, s2.size() - s1.size(), '0');
}

// todo
std::string add(std::string& s1, std::string& s2) {
}

// todo
std::string sub(std::string& s1, std::string& s2) {
}

std::string kmul(std::string& s1, std::string& s2) {
	if (s1.size()>1) {
		int mid = s1.size()/2;
		std::string a(s1.begin(), &s1[mid]);
		std::string b(&s1[mid], s1.end());
		std::string c(s2.begin(), &s2[mid]);
		std::string d(&s2[mid], s2.end());

		std::string ac = kmul(a, c);
		std::string bd = kmul(b, d);
		std::string adplusbc = sub(
				kmul(add(a, b), add(c, d)),
				add(ac, bd)
				);  // ((a+b) * (c+d)) - (ac+bd)
		return // todo (ac + adplusbc + bd)
	} else {
		return (const char*) (int(a)-'0') * (int(b)-'0');
	}
}

int main() {
	std::string a, b, ans;
	std::cout << "Enter 2 numbers: ";
	std::cin >> a >> b;

	bool minus_a = minus(a);
	bool minus_b = minus(b);
	addzeros(a, b);

	if (minus_a ^ minus_b)
		ans = '-' + kmul(a, b);
	else
		ans = kmul(a, b);

	std::cout << "Their multiplication is " << ans << std::endl;
}
