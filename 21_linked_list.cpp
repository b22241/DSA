#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }

};

class List{
    public:
    Node* head;
    Node* tail;

public:
List(){
    head=tail=NULL;
}  
void print(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"-";
        temp = temp->next;
    }
    cout<<"null";

}
void push_front(int val){
    Node*newNode=new Node(val);
    if(head==NULL){
        head=tail=newNode;
        return;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
}
void push_back(int val){
    Node*newNode=new Node(val);
    if(head==NULL){
        head=tail=newNode;
        return;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}
void pop_front(){
    if(head==NULL){
        cout<<"your linkedlist is empyt\n";
        return;
    }
    else;
    head=head->next;
}
void pop_back(){
    if(head==NULL){
        cout<<"your linkedlist is empyt\n";
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
void reverseList() {
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL) {
        Node* nextt = curr->next; // store next
        curr->next = prev;       // reverse pointer
        prev = curr;             // move prev
        curr = nextt;             // move curr
    }
    head = prev;
}
void detectCycle() {            //detect cycle from linked list
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Reset slow to head
            slow = head;

            // Move both one step at a time
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            cout << "Cycle starts at node with value: " << slow->data << endl;
            return;
        }
    }
    cout << "No cycle is present" << endl;
}
};


// int main(){
//     List ll;
//     ll.push_back(1);
//     ll.push_back(2);
//     ll.push_back(3);
//     ll.push_back(4);
//     //ll.push_front(4);
//     //ll.pop_front();
//     //ll.pop_back();
//     //ll.insert(4,1);
//     //cout<<ll.search(3);
//     ll.reverseList();
//     ll.print();
//     ll.head->next->next->next->next->next = ll.head->next;
    //  ll.detectCycle();
    // ll.print();
// }






