#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node* child;
    //parameterized constructor
    Node(int val){
    data=val;
    next=prev=child=NULL;
  }  
};

class Doubly_Linked_List{
    Node* Head;
    Node* Tail;
    public:
    //non-parameterized constructor
    public:
    Doubly_Linked_List(){
        Head=Tail=NULL;
    }
};

