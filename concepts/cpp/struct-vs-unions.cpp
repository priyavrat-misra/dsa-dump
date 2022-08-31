#include <iostream>
using namespace std;

typedef struct {
	int x;
	float y;
	char z;
} st;

typedef union {
	int x;
	float y;
	char z;
} un;

int main() {
	st s;
	s.x = 45;
	s.y = 9.87f;
	s.z = 'H';
	cout << "Size of struct: " << sizeof(st) << endl;
	cout << "{" << s.x << ", " << s.y << ", " << s.z << "}" << endl;

	un u;
	u.x = 45;
	u.y = 9.87f;
	u.z = 'H';
	cout << "Size of union: " << sizeof(un) << endl;
	cout << "{" << u.x << ", " << u.y << ", " << u.z << "}" << endl;
}
