#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
#include <deque>
using namespace std;

class Stack{
    public:
    queue<int>q1;
    queue<int>q2;

    void push(int data){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop(){
        if(q1.empty()){
            cout<<"stack is emopty";
        }
        else{
            q1.pop();
        }
        
    }
    int top(){
        return q1.front();
    }
    bool empty(){
        return q1.size()==0;
    }
    void print(){
        while(!q1.empty()){
            cout<<q1.front()<<" ";
            q1.pop();
        }
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    int ans=s.top();
    cout<<ans;
    //s.print();
}