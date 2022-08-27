// https://www.codechef.com/problems/CSS2
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	unordered_map<int, unordered_map<int, pair<int, int>>> ump;
	while (n--) {
		int id, attr, val, priority;
		cin >> id >> attr >> val >> priority;
		if (ump.count(id) && ump[id].count(attr)) {
			if (ump[id][attr].second <= priority)
				ump[id][attr].first = val;
		} else {
			ump[id][attr] = {val, priority};
		}
	}
	while (m--) {
		int id, attr;
		cin >> id >> attr;
		cout << ump[id][attr].first << endl;
	}
}
