#include <bits/stdc++.h>
using namespace std;


class Student {
public:
    char* name;  // dynamically allocated string
    int age;

    // Constructor
    Student(const char* n, int a) {
        cout<<"i am a parameterised construextor";
        name = new char[strlen(n) + 1];  // allocate memory
        strcpy(name, n);
        age = a;
    }

    // Shallow Copy Constructor
    // Student(Student& s) {
    //     name = s.name;   // <-- copies only the pointer (same address)
    //     age = s.age;
    //     cout << "Shallow Copy Constructor Called\n";
    // }

    // Deep Copy Constructor 
    Student(Student& s) {
        name = new char[strlen(s.name) + 1];  // allocate new memory
        strcpy(name, s.name);                 // copy data, not address
        age = s.age;
        cout << "Deep Copy Constructor Called\n";
    }

    // Destructor
    // Student s; --static memory allocatiin
    // Student *s=new Student()   --dynamic memory allocation
    //deconstructor is called automatically for static memory allocation and we have to call it manually for dynamic memory allocation
    ~Student() {
        delete name;
        cout << "Destructor Called"<< endl;
    }

    void show() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s1("Suman", 21);
    cout << "Original: ";
    s1.show();
    cout<<endl;

    // // Create a shallow copy
    Student s2 = s1;  // copy constructor called
    // cout << "Copied: ";
    // s2.show();
    // cout<<endl;

    s2.name[0] = 'H';  // change first letter of name
    cout << "s1 -> "; s1.show();
    cout << "s2 -> "; s2.show();                 //problem in this shalow copy is that i am changin name of s2 but s1 is also getting changed, to avoid this we have to create deep copy

    return 0;
}
