#include <iostream>

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

class List{
    Node* Head;
    Node* Tail;
    public:
    //non-parameterized constructor
    public:
    List(){
        Head=Tail=NULL;
    }
    void print(){
        Node* temp=Head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
    }
    void push_front(int val){
        Node* newNode=new Node(val);
        if(Head == NULL && Tail == NULL){
            Head=Tail=newNode;
        }
        else{
            newNode->next=Head;
            Head=newNode;
        }
    }
    void push_back(int val){
        Node* newNode=new Node(val);
        if(Head == NULL && Tail == NULL){
            Head=Tail=newNode;
        }
        else{
            Tail->next=newNode;
            Tail=newNode;
        }
    }
    void pop_front(){
        if(Head == NULL && Tail == NULL){
            cout<<"your linked list is empyt, can't pop front";
            return;
        }
        else{
            Node* temp=Head;
            Head=Head->next;
            temp->next=NULL;
            delete(temp);
        }
    }
    void pop_back(){
        if(Head == NULL && Tail == NULL){
            cout<<"your linked list is empyt, can't pop back";
            return;
        }
        else{
            Node* temp=Head;
            while(temp->next!=Tail){
                temp=temp->next;
            }
            temp->next=NULL;
            delete(Tail);
            Tail=temp;
        }
    }
    void insert(int val,int position){
        if(position==0){
            push_front(val);
            return;
        }
        if(position<0){
            cout<<"can't insert";
            return;
        }
        Node* new_node=new Node(val);
        Node* temp=Head;
        int i=0;
        while(i!=position-1){
            if(temp==NULL){
                cout<<"can't insert"<<endl;
                return;
            }
            temp=temp->next;
            i++;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }
    void search_key(int key){
        Node* temp=Head;
        int i=0;
        while(temp!=NULL){
            if(temp->data==key){
                cout<<"key found at index:"<<i;
                return;
            }
            else{
                temp=temp->next;
                i++;
            }
        }
        cout<<"key not found ";
    }
};


int main(){
    List l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_front(4);
    l.push_front(5);
    l.push_front(6);
    l.push_front(7);
    //l.push_back(5);
    //l.push_back(11);
    //l.pop_front();
    //l.pop_back();
    //l.insert(0,20);
    l.print();
    cout<<endl;
    l.search_key(6);
    

}