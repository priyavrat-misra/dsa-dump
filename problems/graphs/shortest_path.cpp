#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
	public:
		int name, parent = -1, distance = -1;
		vector<int> neighbors;
		Node(const int& name) {
			this -> name = name;
		}
};

class Graph {
	private:
		unordered_map<int, Node*> adj_list;
	public:
		Graph(const int& num_nodes) {
			for (int node_no = 0; node_no < num_nodes; ++node_no)
				adj_list[node_no] = new Node(node_no);
		}

		void addEdge(const int& u, const int& v, bool undir = true) {
			adj_list[u] -> neighbors.push_back(v);
			if (undir)
				adj_list[v] -> neighbors.push_back(u);
		}

		void shortestPath(const int& source, const int& dest) {
			queue<int> q;
			q.push(source);
			adj_list[source] -> distance = 0;
			adj_list[source] -> parent = source;

			while (!q.empty()) {
				int f = q.front();
				q.pop();

				for (const int& node : adj_list[f] -> neighbors)
					if (adj_list[node] -> parent == -1) {
						q.push(node);
						adj_list[node] -> distance = 1 + adj_list[f] -> distance;
						adj_list[node] -> parent = f;
					}
			}

			cout << "shortest path:";
			int i = dest;
			while (i != source) {
				cout << " " << i;
				i = adj_list[i] -> parent;
			}
			cout << " " << i << endl;
			cout << "distance: " << adj_list[dest] -> distance << endl;
		}

		~Graph() {
			for (const pair<int, Node*> node : adj_list)
				delete node.second;
		}
};

int main() {
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(3, 5);
	g.addEdge(5, 6);
	g.addEdge(4, 5);
	g.addEdge(0, 4);
	g.addEdge(3, 4);
	g.addEdge(2, 3);
	g.shortestPath(1, 3);
}
