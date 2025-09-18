#include<algorithm>
#include<iostream>
#include<vector>
#include<list>
using namespace std;

//STACK USING VECTOR
// class stack{
//     vector<int> v;

// /// all operations are in O(1);
//     public:
//     void push(int val){
//         v.push_back(val);
//     }
//     void pop(){
//         v.pop_back();
//     }
//     int top(){
//         return v[v.size()-1];
//     }
//     bool empty(){
//         return v.size()==0;
//     }

// };

// int main(){
//     stack s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }

// }



//STACK USING LINKED LIST
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }

};
class stack{
    list<int>ll;
    public: 
    void push(int val){
        ll.push_front(val);
    }
    void pop(){
        ll.pop_front();
    }
    int top(){
        return ll.front();
    }
    bool empty(){
        return ll.size()==0;
    }
};


int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.top();
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
}