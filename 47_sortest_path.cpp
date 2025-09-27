#include <bits/stdc++.h>
using namespace std;

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
        l[u].push_back(v); 
        l[v].push_back(u);          //THIS IF UnDIRECTED GRAPH
    }
    void print(){
        for(int i=1;i<=V;i++){
            cout<<i<<" : ";
            for(auto neigh:l[i]){
            cout<<neigh<<" ";
        }
        cout<<endl;
        }
    }

void bfs() {                          //this function finds thesorted path between any two given nodes by using bfs method
    vector<int> parent(V+1, -1);
    vector<bool> visited(V+1, false);
    queue<int> q;
    int from=1;
    int to=8;
    
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto neigh : l[curr]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                parent[neigh] = curr;   // store parent
                q.push(neigh);
            }
        }
    }
	vector<int>ans;
	int current=to;
	ans.push_back(current);

	while(current!=from){
		current=parent[current];
		ans.push_back(current);
	}

	reverse(ans.begin(),ans.end());
	for(int val:ans){
        cout<<val<<"->";
    }
}
};

int main() {
    Graph g(8);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 8);
    g.addEdge(4, 6);
    g.addEdge(5, 8);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    // g.print();
    // g.bfs();
    int a=5>>1;
    cout<<a;
}
