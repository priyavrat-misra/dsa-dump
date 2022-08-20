#include <iostream>
#include <unordered_map>
#include <bitset>
using namespace std;

class Graph {
public:
	const int n;
	Graph(int numVertices) : n(numVertices) {}
	unordered_map<int, bitset<5>> adjList;

	void addEdge(const int& u, const int& v, bool undir = true) {
		adjList[u].set(v);
		if (undir)
			adjList[v].set(u);
	}

	int numTriangles() {
		int ans = 0;
		// go through all pairs of vertices
		for (int i = 0; i < n - 1; ++i)
			for (int j = i + 1; j < n; ++j)
				if (adjList[i][j]) // if they are neighbors
					ans += (adjList[i] & adjList[j]).count(); // intersection to find common neighbors

		return ans / 3; // since each triangle is counted thrice above
	}
};

int main() {
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(0, 4);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	cout << g.numTriangles() << endl;
}
