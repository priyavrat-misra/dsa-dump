#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(int argc, const char* argv[]) {
	if (argc != 3 || strlen(argv[1]) != 8) {
		cerr << "usage: computime hh:mm:ss speed" << endl;
		return EXIT_FAILURE;
	}
	int h = atoi(argv[1]), m = atoi(argv[1] + 3), s = atoi(argv[1] + 6);
	double speed = atof(argv[2]);
	double time = (h * 3600 + m * 60 + s) / speed;
	h = time / 3600;
	m = (time - h * 3600) / 60;
	cout << h << ":" << m << ":" << time - h * 3600 - m * 60 << endl;
	return EXIT_SUCCESS;
}
