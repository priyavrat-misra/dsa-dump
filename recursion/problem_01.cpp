// karatsuba multiplication for large integers
#include <iostream>
#include <string>

bool minus(std::string& s) {
	if (s[0] == '-') {
		s.erase(s.begin());
		return true;
	}
	return false;
}

void ridzeros_(std::string& s) {
	while (s.size()!=1 && s[0]=='0')
		s.erase(s.begin());
}

void addzeros_(std::string& s1, std::string& s2) {
	if (s1.size() > s2.size())
		s2.insert(0, s1.size() - s2.size(), '0');
	else if (s1.size() < s2.size())
		s1.insert(0, s2.size() - s1.size(), '0');

	if (s1.size()!=1 && s1.size()%2) {
		s1.insert(0, 1, '0');
		s2.insert(0, 1, '0');
	}
}

std::string add(std::string& s1, std::string& s2) {
	addzeros_(s1, s2);
	if (s1.size() == 1) {
		return std::to_string(std::stoi(s1) + std::stoi(s2));
	} else {
		std::string res;
		std::string::reverse_iterator it1 = s1.rbegin();
		std::string::reverse_iterator it2 = s2.rbegin();
		int i, carry = 0;
		while (it1 != s1.rend()) {
			i = int(*it1) + int(*it2) + carry - 2 * '0';
			carry = 0;
			if (i>9) {
				carry = 1;
				i -= 10;
			}
			res.insert(0, 1, char(i+'0'));
			++it1;
			++it2;
		}
		if (carry)
			res.insert(0, 1, '1');
		
		ridzeros_(res);
		return res;
	}
}

std::string sub(std::string& s1, std::string& s2) {
	addzeros_(s1, s2);
	if (s1.size() == 1) {
		return std::to_string(std::stoi(s1) - std::stoi(s2));
	} else {
		std::string one("1");
		std::string res;
		std::string::reverse_iterator it = s2.rbegin();
		int i;
		while (it != s2.rend()) {
			i = 9 - (int(*it)-'0');
			res.insert(0, 1, char(i+'0'));
			++it;
		}
		res = add(res, one);
		res = add(s1, res);
		ridzeros_(res);
		res.erase(res.begin());

		return res;
	}
}

std::string kmul(std::string& s1, std::string& s2) {
	addzeros_(s1, s2);
	if (s1.size() == 1) {
		return std::to_string(std::stoi(s1) * std::stoi(s2));
	} else {
		int mid = s1.size()/2;
		std::string a(s1, 0, mid);
		std::string b(s1, mid, mid);
		std::string c(s2, 0, mid);
		std::string d(s2, mid, mid);
		
		std::string aplusb = add(a, b);
		std::string cplusd = add(c, d);
		std::string apbcpd = kmul(aplusb, cplusd);

		std::string ac = kmul(a, c);
		std::string bd = kmul(b, d);
		std::string acplusbd = add(ac, bd);
		
		// ((a+b) * (c+d)) - (ac+bd)
		std::string adplusbc = sub(apbcpd, acplusbd);
		
		// 10^n * ac + 10^n/2 * adplusbc + bd
		ac.append(2*mid, '0');
		adplusbc.append(mid, '0');
		std::string t = add(ac, adplusbc);
		
		return add(t, bd);
	}
}

int main() {
	std::string a, b, ans;
	std::cout << "Enter 2 numbers: ";
	std::cin >> a >> b;

	bool minus_a = minus(a);
	bool minus_b = minus(b);

	if (minus_a ^ minus_b)
		ans = '-' + kmul(a, b);
	else
		ans = kmul(a, b);

	std::cout << "Their multiplication is: " << ans << std::endl;
}
