#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;                  // number of vertices
    list<int>* l;           // adjacency list
public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V + 1];   // 1-based indexing
    }

    void addEdge(int u, int v) { 
        l[u].push_back(v);           //THIS IF DIRECTED GRAPH
    }

    void DFS(vector<bool>& visited, stack<int>& m, int i) {  // pass by reference
        visited[i] = true;

        for (int neigh : l[i]) {
            if (!visited[neigh]) {
                DFS(visited, m, neigh);
            }
        }

        m.push(i);  // push after exploring all neighbors
    }
        /// topological sort using bfs
    void topologicalSort() {
        vector<bool> visited(V + 1, false);
        stack<int> m;

        // run DFS for all nodes
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                DFS(visited, m, i);
            }
        }

        // print stack contents
        while (!m.empty()) {
            cout << m.top() << " ";
            m.pop();
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(3, 4);
    g.addEdge(5, 6);

    cout << "Topological Sort: ";
    g.topologicalSort();
    return 0;
}
