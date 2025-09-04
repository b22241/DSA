#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;


//search time for ordered map is O(logn) and for unorderd map is O(1)
int main(){
    unordered_map<string,int>m;
    m.insert({"ram",20});
    m["shyam"]=30;
    m["shiv"]=40;
    // cout<<m["ram"];
    // cout<<m.at("ram");
    for(auto p:m){
        cout<<p.first<<"-"<<p.second<<endl;
    }
}
