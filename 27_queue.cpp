#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
#include <deque>
using namespace std;


class Node{
  public:
  int data;
  Node* next;
  //parameterized constructor
  Node(int val){
    data=val;
    next=NULL;
  }
};

class Queue{
    Node* head;
    Node* tail;
    public:
    //non-parameterized constructor
    public:
    Queue(){
        head=tail=NULL;
    }

    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    int front(){
        if(head!=NULL){
            return head->data;
        }
        return -1;
    }
    void push(int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void pop(){
        if (empty()){
            cout<<"queue is empty";
        }
        else{
            Node* temp=head;
            head=head->next;
            delete(temp);
        }
    }
    bool empty(){
        return head==NULL;
    }
};


int main(){
    // Queue q;
    // q.push(2);
    // q.push(3);
    // q.push(9);
    // q.push(4);
    // q.push(5);
    // //q.pop();
    // q.front();
    // q.empty();
    // //q.print();

    //we can use deque as well, queue and deque are standard libary in CPP
    deque<int>d;
    d.push_back(2);
    d.push_back(4);
    d.push_front(1);
    cout<<d.front()<<d.back();
    
}


