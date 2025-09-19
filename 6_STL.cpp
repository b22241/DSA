#include <iostream>
#include <algorithm>  // For sort()
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;


// int main(){
///VECTORS
//     vector <int> vec={4,2,3,55,323,2,4,5,26,74,34,53};
//     vector <int> vec={3,10};  {10,10,10}
//     vector <int> vec2{vec};  {10,10,10}  //copy of vector
//     for(int val:vec){
//         cout<<val<<" ";
//     }
//     cout<<endl;
//     //vec.push_back(100);
//     //vec.pop_back();
//     //vec.erase(vec.begin()+3);         //O(n)
//     //vec.erase(vec.begin(),vec.end()-1);
//     //vec.insert(vec.begin()+1,10);      //O(n)
//    // vec.clear();
//    //cout<<vec.empty();   prints 0 or 1 
//   
//    vector<int> ::iterator it;
//     for(it = vec.begin(); it != vec.end(); it++) {
//         cout << *it << " ";
//     }
//     cout<<endl;
//     for(auto it = vec.rbegin(); it != vec.rend(); it++) {
//         cout <<*it << " ";
//     }
//     cout<<endl;
//     cout<<*(max_element(vec.begin(),vec.end())) endl;
//     cout<<binary_search(vec.begin(),vec.end(),target)   returns 0 or 1
// }


//LIST
// random accces is not possible in list unlike vector,arr,deque
//DEQUE
// int main(){
//     list<int> l;
//     deque<int> d={2,436,3,6,785,34,10};
//     l.push_back(2);
//     l.push_back(9);
//     l.push_back(-1);
//     l.push_back(36);
//     l.push_back(6);
//     l.push_back(12);
//     //l.pop_back();
//     //l.emplace_back(2);
//     for ( int val:l){
//         cout<<val<<" ";
//     }
//     cout<<endl;
//     cout<<d[1];
// }


//pair
// int main(){
//     pair <string,int> p={"34343fsge",2};
//     pair<int ,pair<string, int>> p1={1,{"fsfd",3}};
//     cout<<p1.first<<endl;
//     cout<<p1.second.first;
// }

 
//stack  //LIFO  O(1)
// int main(){
//     stack<int> s ;
//     s.push(1);
//     s.push(4);
//     s.push(432);
//     s.push(12);
//     s.push(9);
//     s.pop();
//     stack<int>s2;
//     s2.swap(s);  //pushes all values of stack s to another stack s2
//     cout<<s.top();
//     cout<<s.size()<<endl;
//     cout<<s.empty()<<endl;
//     cout<<s.top()<<endl;
// }


// Queue   //FIFO  allfunctions are same as stack
// int main() {
//     queue<int> q;
//     q.push(10);
//     q.push(20);
//     q.push(30);
//     cout << "Front: " << q.front() << endl;  // 10
//     cout << "Back: " << q.back() << endl;    // 30
//     cout << "Size: " << q.size() << endl;    // 3
//     q.pop();  // remove 10
//     cout << "After pop, front: " << q.front() << endl; // 20
//     cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;
// }


//priority queue   data is stored in maxheap or minheap format. it's stored in storted order  complexity-O(logn)
// int main(){
//     priority_queue<int>q;
//     q.push(2);
//     q.push(4);
//     q.push(21);
//     q.push(-1);
    //    q.pop();
// q.size();
// q.empty();
//     cout<<q.top();
// }


//map  sort by key values
//time complexity O(logn);
// int main(){
//     map<string,int>m;
//     m["tv"]=50;
//     m["laptop"]=100;
//     m["headphone"]=20;
//     m["tab"]=30;
//     m.insert({"camera",23});
    // m.emplace("camera1",23); 
//     m.erase("tv");
//     cout<<m["tab"]<<endl;
//     for(auto p:m){
//         cout<<p.first<<" "<<p.second<<endl;
//     }
// if(m.find("camera")!=m.end()){
    // cout<<"camera found";
// }
// }


//multimap ===allows duplicate values of a attribute,everything is same as map, b
// int main(){
//     multimap<string,int>m;
//     m.emplace("tv",23);
//     m.emplace("tv",24);
//     m.emplace("tv",22);
//     m.emplace("tv",4345);
//     m.erase("tv");   sari values khali ho jaegi
//       m.erase(m.find("tv"));   phli value hi clear hogi
//     for(auto p:m){
//                 cout<<p.first<<" "<<p.second<<endl;
//             }
        // }


//unordered_map , arranges data in random order
//time complexity O(1);
//search time for ordered map is O(logn) and for unorderd map is O(1),every operation happens in constast time in unordered map
// int main(){
//     unordered_map<string,int>m;
//     m.emplace("tv",23);
//     m.emplace("tv",24);
//     m.emplace("tab",24);
//     m.emplace("phone",22);
//     m.emplace("moble",4345);
//     //m.erase("tv");
//     m.insert({"ram",20});
//     m["shyam"]=30;
    // m["shiv"]=40;
//     // cout<<m["ram"];
//     // cout<<m.at("ram");
//     for(auto p:m){
//         cout<<p.first<<"-"<<p.second<<endl;
//     }
// }


//set ==>stores only uniques values in sorted order
//unordered_set ==>stores only uniques values in random order
//multiset==> stores duplicate values as well
//time complexity O(logn)
// int main(){
//     set<int>s;
//     s.insert(4);
//     s.insert(2);
//     s.insert(3);
//     s.insert(23);
//     s.insert(4);
//     cout<<s.size()<<endl;   
//     cout<<*(s.lower_bound(5))<<endl;  //if 5 is there then returns 5, else gives a value bigger than 5,else gives 0
//     cout<<*(s.upper_bound(3));
// }

//sorting
// int main(){
//     int arr[]={2,143,53,2,1,5,6};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     //reverse(arr,arr+n);
    //     for (int val:arr){
//         cout<<val<<" ";
//     }
//     cout<<endl;
    //     //sort(arr,arr+n);
//     //sort(arr,arr+n,greater<int>()); ///to sort in descending order
//     //sort(vec.begin(),vec.end());
    //     for (int val:arr){
//         cout<<val<<" ";
//     }
//     cout<<endl;
// }


//next_permutation  next_permutation(vec.begin(),vec.end());
//previouse_permutation    previous_permutation(vec.begin(),vec.end());
//swap   swap(a,b);
//min   *min_element(vec.begin(),vec.end())
//max   *max_element(vec.begin(),vec.end())
//builtin_popcount  cout<<__builtin_popcountll(15);   4(number of bits)