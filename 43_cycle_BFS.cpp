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
    

};


int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);;
    g.addEdge(3,4);
    // g.printGraph();
}
