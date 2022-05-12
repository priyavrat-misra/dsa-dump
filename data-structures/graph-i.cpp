#include <iostream>
#include <list>
using namespace std;

class Graph {
	private:
		int v;
		list<int> *l;
	public:
		Graph(int v) {
			this -> v = v;
			l = new list<int>[v];
		}

		void addEdge(const int& u, const int& v, bool undir = true) {
			l[u].push_back(v);
			if (undir)
				l[v].push_back(u);
		}

		void printAdjList() {
			for (int i = 0; i < v; ++i) {
				cout << i << " --> |";
				for (int node : l[i])
					cout << " " << node << " |";
				cout << endl;
			}
		}

		~Graph() {
			delete[] l;
		}
};

int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(1, 3, false);
	g.addEdge(2, 0);
	g.printAdjList();
}
