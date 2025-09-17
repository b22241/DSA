#include<algorithm>
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;  // Initialize prev pointer
    }
};

class DoublyList{
    Node* head;
    Node* tail;

    public:
    DoublyList(){
        head = tail = NULL;
    }

    void print(){
        Node* temp = head;
        cout<<"NULL-";
        while(temp != NULL){
            cout << temp->data << "-";
            temp = temp->next; 
        }
        cout << "NULL\n";  // Add newline for better output
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;  // Correct assignment
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;  // Correct assignment
        }
        else{
            newNode->next =NULL;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_front(){
        if(head == NULL){
            cout<<"linkedlist is empty";
        }
        else{
            head=head->next;
            head->prev=NULL;
        }
    }
    void pop_back(){
        if(head==NULL){
            cout<<"your doublylinkedlist is empyt\n";
            return;
        }
        else;
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }
    void insert(int val,int position){
    if(position<0) return;
    if (position==0) return push_front(val);
    else;
    Node* temp=head;
    Node*newNode=new Node(val);
    for(int i=0;i<position-1;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
    int search(int val){
    Node* temp=head;
    int idx=0;
    while(temp!=NULL){
        if(temp->data==val){
            return idx;
        }
        temp=temp->next;
        idx++;
    }
    return -1;
}
    void reverse(int k){
    Node* temp1=head;
    Node* temp2=head;
    Node* temp3=head;
    while(int i=0<k){
        temp2=temp2->next;
    }
    temp3->data=temp2->data;
    temp2->data=temp1->data;
    temp1->data=temp3->data;


}
};

int main(){
    DoublyList ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    // ll.push_back(0);
    //ll.pop_front();
    // ll.pop_back();
    // cout<<ll.search(3);
    // ll.print();
    return 0;
}