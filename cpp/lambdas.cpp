#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparator(const string& left, const string& right) {
	return left.size() < right.size();
}

int main() {
	vector<string> v = {
		"cat",
		"puppy",
		"antelope",
		"bear"
	};
	sort(
		v.begin(),
		v.end(),
		[](const string& left, const string& right) {
			return left.size() < right.size();
		}
	);
	// is same as
	// sort(v.begin(), v.end(), comparator);

	for (auto i = v.begin(); i != v.end(); ++i)
		cout << *i << endl;
}
