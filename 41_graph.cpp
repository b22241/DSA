#include<bits/stdc++.h>
using namespace  std;

class Graph{
    int V;         //number of vertices
    list<int> *l;         //lists are created to store informations of vertices
    public: 
    Graph(int V){
        this->V=V;
        l=new list<int>[V];        //a arr named l is created which has V lists in it.
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void printGraph(){
        for(int i=0;i<V;i++){
            cout<<i<<" : ";
            for(int val:l[i]){
                cout<<val<<" ";
            }
            cout<<endl;
        }
    }
    void BFS(){            //travel to immediate neighbours first  //time complexity -O(number of vertices+number of edges)
        queue<int>q;
        q.push(0);
        vector<bool>visited(V,false);
        visited[0]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cout<<u<<" ";
            for(int v:l[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
    }
    void dfsHelper(int u,vector<bool>&visited){
        cout<<u<<" ";
        visited[u]=true;
        for(int v:l[u]){
            if(!visited[v]){
                dfsHelper(v,visited);
            }
        }
    }
    void DFS(){            //keeping on visiting 1st unvisited neighbour
        vector<bool>visited(V,false);
        int src=0;
        dfsHelper(src,visited);
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);;
    g.addEdge(2,4);
    g.printGraph();
    // g.BFS();
    // g.DFS();
}