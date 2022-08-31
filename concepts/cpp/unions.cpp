#include <iostream>
using namespace std;

typedef struct {
	const char* name;
	bool isrobot;
	union {
		const char* personality;
		int firmware_version;
	};
} character;

void print_character(character* c) {
	cout << "Character: " << c -> name << " -- ";
	if (c -> isrobot)
		cout << "Firmware version: " << c -> firmware_version;
	else
		cout << c -> personality;

	cout << endl;
}

int main() {
	character hansolo;
	hansolo.name = "Han Solo";
	hansolo.isrobot = false;
	hansolo.personality = "Scruffy-looking Nerfherder";

	character r2d2;
	r2d2.name = "R2";
	r2d2.isrobot = true;
	r2d2.firmware_version = 42;

	print_character(&hansolo);
	print_character(&r2d2);
}
