// tower of hanoi
#include <iostream>

void move(int n, char src, char hlpr, char dest) {
	if (n > 0) {
		move(n - 1, src, dest, hlpr);
		std::cout << "Move " << src << " to "
			<< dest << "." << std::endl;
		move(n - 1, hlpr, src, dest);
	}
}

int main() {
	int n;
	std::cout << "Enter the number of rings: ";
	while (true) {
		if (std::cin >> n && n > 0)
			break;
		else
			std::cerr << "Not a natural number. Try Again." << std::endl;
	}
	move(n, 'A', 'B', 'C');
}
