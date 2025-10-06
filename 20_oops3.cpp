#include<bits/stdc++.h> 
using namespace std;

class A {
public:
    int name;
    int age;
    void property() {
        cout << "A";
    }
};

class B :public A {   
public:
    char val;
    void property() {
        cout << "B";
    }
};

class C :public B {

};

int main() {
    C obj;
    obj.property();         //-- by default it will inherit form B
    // obj.A::property();   //--A //we have to tell manually which class properties we are will to inherit
    // obj.B::property();   //--B
}
