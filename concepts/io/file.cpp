#include <fstream>
#include <bitset>
using namespace std;

int main() {
	{
		ofstream of("log.txt");
		of << "Hello, World!" << endl;
		of << bitset<8>(255) << endl;
	}
}
