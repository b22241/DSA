#include<algorithm>
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;

 //    -------------------------------------------------------Stack Using Vector--------------------------------------------------------------------------
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



 //    -------------------------------------------------------Stack Using Linked List--------------------------------------------------------------------------
// class stack{
//     list<int>ll;
//     public: 
//     void push(int val){
//         ll.push_front(val);
//     }
//     void pop(){
//         ll.pop_front();
//     }
//     int top(){
//         return ll.front();
//     }
//     bool empty(){
//         return ll.size()==0;
//     }
// };


// int main(){
//     stack s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     // cout<<s.top();
//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }
// }


                        //    -------------------------------------------------------Stack Using queue--------------------------------------------------------------------------
// Approach 1 (Costly push)
// push(x) → O(n) (move all elements every time you insert).
// pop() → O(1) (just pop front of q1).
// top() → O(1).
// Best if you expect many pops compared to pushes.
// 🔹 Approach 2 (Costly pop)
// push(x) → O(1) (just push into q1).
// pop() → O(n) (move elements until last, then pop it).
// top() → O(n).
// Best if you expect many pushes and fewer pops.
// If your use case has frequent pop() / top() calls → Approach 1 is better.
// If your use case has frequent push() calls but fewer pop() → Approach 2 is better.
// class Stack {
//     queue<int> q1, q2;
//     public:
//     void push(int val) {
//         q2.push(val);          // Step 1: Push new element into q2
//         // Step 2: Move everything from q1 → q2
//         while (!q1.empty()) {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         swap(q1, q2);          // Step 3: Swap q1 and q2
//     }

//     void pop() {
//         if (q1.empty()) {
//             cout << "Stack is empty\n";
//             return;
//         }
//         q1.pop();
//     }

//     int top() {
//         if (q1.empty()) {
//             cout << "Stack is empty\n";
//             return -1;
//         }
//         return q1.front();
//     }

//     bool empty() {
//         return q1.empty();
//     }

//     int size() {
//         return q1.size();
//     }
// };

// int main() {
//     Stack s;
//     s.push(10);
//     s.push(20);
//     s.push(30);

//     cout << "Top: " << s.top() << endl; // 30
//     s.pop();
//     cout << "Top after pop: " << s.top() << endl; // 20
//     s.pop();
//     cout << "Top after another pop: " << s.top() << endl; // 10
// }


    // -------------------------------------------------------Queue using Stack--------------------------------------------------------------------------
// class Queue{
//     stack<int>s1,s2;
//     public:
//     void push(int val){
//         while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(val);
//         while(!s2.empty()){
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }
//     void pop(){
//         s1.pop();
//     }
//     int front(){
//         return s1.top();
//     }
//     bool empty(){
//         return s1.size()==0;
//     }

// };

// int main(){
//     Queue q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     q.push(5);
//     q.pop();
//     cout<<q.front();
// }