#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
	public:
		int node_no;
		vector<int> neighbors;
		Node(const int& node_no) {
			this -> node_no = node_no;
		}
};

class Graph {
	private:
		int num_nodes;
		unordered_map<int, Node*> m;
	public:
		Graph(const int& num_nodes) {
			this -> num_nodes = num_nodes;
			for (int node_no = 0; node_no < num_nodes; ++node_no)
				m[node_no] = new Node(node_no);
		}

		void addEdge(const int& a, const int& b, bool undir = true) {
			m[a] -> neighbors.push_back(b);
			if (undir)
				m[b] -> neighbors.push_back(a);
		}

		void bfs(const int& source) {
			queue<int> q;
			vector<bool> is_visited(num_nodes, false);
			
			q.push(source);
			is_visited[source] = true;

			cout << "BFS:";
			while (!q.empty()) {
				int f = q.front();
				cout << " " << f;
				q.pop();

				for (const int& neighbor : m[f] -> neighbors)
					if (!is_visited[neighbor]) {
						q.push(neighbor);
						is_visited[neighbor] = true;
					}
			}
			cout <<  endl;
		}

		~Graph() {
			for (const pair<int, Node*>& node : m)
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
	g.bfs(1);
}
