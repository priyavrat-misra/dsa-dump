#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
	public:
		int node_no;
		bool is_visited = false;
		vector<int> neighbors;
		Node(const int& node_no) {
			this -> node_no = node_no;
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

		void addEdge(const int& a, const int& b, bool undir = true) {
			adj_list[a] -> neighbors.push_back(b);
			if (undir)
				adj_list[b] -> neighbors.push_back(a);
		}

		void bfs(const int& source) {
			queue<int> q;
			q.push(source);
			adj_list[source] -> is_visited = true;

			cout << "BFS:";
			while (!q.empty()) {
				int f = q.front();
				cout << " " << f;
				q.pop();

				for (const int& neighbor : adj_list[f] -> neighbors)
					if (!adj_list[neighbor] -> is_visited) {
						q.push(neighbor);
						adj_list[neighbor] -> is_visited = true;
					}
			}
			cout <<  endl;
		}

		~Graph() {
			for (const pair<int, Node*>& node : adj_list)
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
	g.bfs(2);
}
