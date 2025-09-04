#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
#include <deque>
using namespace std;

class CircularQueue{
    int* arr;
    int current_sixe,capacity;
    int f,r;
    
    public:
    CircularQueue(int size){
        capacity=size;
        arr=new int[capacity];
        current_sixe=0;
        f=0;
        r=-1;
    }
    void push(int data){
        if(current_sixe==capacity){
            cout<<"it's full";
            return;
        }
        else{
             r=(r+1)%capacity;
             arr[r]=data;
             current_sixe++;
        }
    }
    void pop(){
        if(empty()){
            cout<<"it's empty";
            return;
        }
        else{
            f=(f+1)%capacity;
            current_sixe--;
        }
    }
    int front(){
        if(empty()){
            cout<<"it's empty";
            return -1;
        }
        else{
             return arr[f];
        }
       
    }
    bool empty(){
        return current_sixe==0;
    }
    void print(){
        for(int i=0;i<current_sixe;i++){
            cout<<arr[i]<<" ";
        }
    }
};


int main(){
    CircularQueue q(2);
    q.push(1);
    q.push(2);
   
    //q.print();
}