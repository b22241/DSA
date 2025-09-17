#include<algorithm>
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class CircularList{
    Node* head;
    Node* tail;

    public:
    CircularList(){
        head = tail = NULL;
    }
    void print(){
        cout<<head->data<<"->";
        Node* temp = head->next;
        while(temp != head){
            cout << temp->data << "->";
            temp = temp->next; 
        }
        cout <<head->data;  // Add newline for better output
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;  
            tail->next=head;
        }
        else{
            newNode->next = head;
            head=newNode;
            tail->next=newNode;
        }
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;  
            tail->next=head;
        }
        else{
            tail->next = newNode;
            newNode->next=head;
            tail=newNode;
        }
    }
    void pop_front(){
        if(head==NULL) return;
        else if(head==tail){
            delete tail;
            head=tail=NULL;
        }
        else{
            Node* temp=head;
            head=head->next;
            tail->next=head;
            temp->next=NULL;
            delete temp;        
        }
    }
    void pop_back(){
        if(head==NULL) return;
        else if(head==tail){
            delete tail;
            head=tail=NULL;
        }
        else{
            Node* temp=tail;
            Node* prev=head;
           while(prev->next!=tail){
            prev=prev->next;
           }   
           tail=prev;
           tail->next=head;
           temp->next=NULL;
           delete temp;
        }
        }
};

int main(){
    CircularList ll;
    // ll.push_front(1);
    // ll.push_front(2);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    //ll.pop_front();
    // ll.pop_back();

    ll.print();
    return 0;
}
