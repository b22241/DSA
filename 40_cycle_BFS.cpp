#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;         //number of vertices
    list<int> *l;         //lists are created to store informations of vertices
    public: 
    Graph(int V){
        this->V=V;
        l=new list<int>[V];        //a arr is created which has V lists in it.
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
    bool cycle_BFS(){        
        queue<pair<int,int>>q;
        q.push({0,-1});
        vector<bool>visited(V,false);
        visited[0]=true;
        while(!q.empty()){
            int u=q.front().first;
            int uParent=q.front().second;
            q.pop();
            for(int v:l[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push({v,u});
                }
                else if(uParent!=v){         //condition for cycle
                    return true;
                }
            }
        }
        return false;
    }

};


int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);;
    g.addEdge(3,4);
    // g.printGraph();
    cout<<g.cycle_BFS();
}
