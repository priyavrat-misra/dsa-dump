#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
	public:
		string name;
		list<string> neighbors;

		Node(const string& name) {
			this -> name = name;
		}
};

class Graph {
	private:
		unordered_map<string, Node*> m;
	public:
		Graph(const vector<string>& cities) {
			for (string city : cities)
				m[city] = new Node(city);
		}

		void addEdge(const string& x, const string& y, bool undir = false) {
			m[x] -> neighbors.push_back(y);
			if (undir)
				m[y] -> neighbors.push_back(x);
		}

		void printAdjList() {
			for (auto row : m) {
				cout << row.first << " --> |";
				for (string neighbor : row.second -> neighbors)
					cout << " " << neighbor << " |";
				cout << endl;
			}
		}

		~Graph() {
			for (pair<string, Node*> row : m)
				delete row.second;
		}
};

int main() {
	Graph g({"NY", "WC", "LA", "AZ"});
	g.addEdge("NY", "WC");
	g.addEdge("AZ", "WC");
	g.addEdge("LA", "AZ");
	g.printAdjList();
}
