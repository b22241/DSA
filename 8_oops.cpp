#include<iostream>
#include<string>
using namespace std;

//Incapsulation & Abstraction
// class Teacher{
//     private:
//     double salary;

//     public:
//     //non-parameteried constructor 
//     Teacher(){
//         dept="computer science";
//     }

//     //parameteried constructor 
//     Teacher(string n,string dep,string sub,double s){
//         this->name=n;
//         dept=dep;
//         subject=sub;
//         salary=s;
//     }
//     //Custom Copy constructor
//     Teacher(Teacher &orgObj) {
//         cout << "I am custom copy constructor...\n";
//         this->name = orgObj.name;
//         this->dept = orgObj.dept;
//         this->subject = orgObj.subject;
//         this->salary = orgObj.salary;
//     }


//     string name;
//     string dept;
//     string subject;

//     //setter
//     void changeDept(string newDept){
//         dept=newDept;
//     }
//     void getInfo(){
//         cout<<"name: "<<name<<endl;
//         cout<<"department: "<<dept<<endl;
//         cout<<"subject: "<<subject<<endl;
//     }

//     //getter
//     double getsalary(){
//         return salary;
//     }
// };

// class Student{
//     public:
//     string name;
//     double* cgpaPtr;
//     //parameteried constructor
//     Student(string name,double cgpa){
//         this->name=name;
//         cgpaPtr = new double;
//         *cgpaPtr=cgpa;

//     }

//     //copy constructor
//     Student(Student &student) {
//         cout << "I am custom copy constructor...\n";
//         this->name = student.name;
//         this->cgpaPtr= student.cgpaPtr;
//     }

//     //destructor
//     ~Student(){
//         cout<<"I delete everything";
//     }
//     void getInfo(){
//         cout<<"name: "<<name<<endl;
//         cout<<"cgpa: "<<*cgpaPtr<<endl;
//     }

// };
// int main(){
//     //non-parameteried constructor call
//     // Teacher t1;
//     // t1.name="Ram";
//     // t1.dept="cc";
//     // t1.subject="VLSI";

//     // //parameteried constructor call
//     // Teacher t1("shyam","electrical","nanotechnology",1000);
//     // Teacher t2(t1);
//     // //t1.getInfo();
//     // t2.getInfo(); ///use of copy constructor//it's deafulat but we can make custom as well
   

//     Student s1("anand sanva",8.1);
//     //Student s2(s1);//default copy constructor
//     cout<<"Student 1"<<endl;
//     //s1.getInfo();
//     Student s2(s1);//customised copy constructor
//     *(s2.cgpaPtr)=9.2;
//     cout<<"Student 1"<<endl;
//     s2.getInfo();
// }


//single level Inheritence
// class Person{
//     public:
//     string name;
//     int age;
//     //parameterised constructor
//     Person(){
       
//     }

// };

// class Student :public Person{
//     //student has attributes name,age,roll number. so we don't need to define name and age again, we will inherit name and age from Person class(in this case this is parent and student is child)
//     public:
//     string roll_number;
//     void getInfo(){
//         cout<<"name: "<<name<<endl;
//         cout<<"roll number: "<<roll_number<<endl;
//         cout<<"age: "<<age<<endl;
//     }
// };

// int main(){
//     Student s1;
//     s1.name="rahul";
//     s1.age=90;
//     s1.roll_number="B22241";
//     s1.getInfo(); //even though student class has no paraments like name and age, but it's taking info from person class;
// }


//multilevel inheritence
// class Person{
//     public:
//     string name;
//     int age;
// };

// class Student :public Person{
//     //student has attributes name,age,roll number. so we don't need to define name and age again, we will inherit name and age from Person class(in this case this is parent and student is child)
//     public:
//     string roll_number;
// };

// class GradStudent:public Student{
//     public:
//     string research_area;
//     void getInfo(){
//         cout<<"name: "<<name<<endl;
//         cout<<"roll number: "<<roll_number<<endl;
//         cout<<"research_area: "<<research_area<<endl;
//     }
// };

// int main(){
//    GradStudent g1;
//    g1.name="Harsh";
//    g1.roll_number="B21301";
//    g1.research_area="AI/ML";
//    g1.getInfo();
// }


//Multiple Inheritence
// class Student{
//     public:
//     string name;
// };
// class Teacher{
//     public:
//     string subject;
//     double salary;
// };
// class TA:public Student,public Teacher{
//     public:
//     string reasearch_area;
//     void getInfo(){
//         cout<<"name: "<<name<<endl;
//         cout<<"subject: "<<subject<<endl;
//         cout<<"salary: "<<salary<<endl;
//         cout<<"reasearch_area: "<<reasearch_area<<endl;
//     }
// };

// int main(){
//     TA t1;
//     t1.name="Aman";
//     t1.subject="Thermodynamics";
//     t1.salary=50000;
//     t1.reasearch_area="heat";
//     t1.getInfo();
// }


                                                                                      //Polymorphism
                                                                                      //Compile Type Polymorphism
//eg. constructor overloading
// class Student {
// public:
//     string name;
//     // Non-parameterized constructor
//     Student() {
//         cout << "non-parameterized\n";
//     }
//     // Parameterized constructor
//     Student(string name) {
//         this->name = name;
//         cout << "parameterized\n";
//     }
// };

// int main() {
//     //Student s1();  //if i write just s1 then non parameterised constuctor will run 
//     Student s1("tony stark");  //if i write name as well then parameterised will run, this phenomena is knows as constructor overloading
//     return 0;
// }


//eg.function overloading
// class Print {
// public:
//     void show(int x) {
//         cout << "int : " << x << endl;
//     }
//     void show(char ch) {
//         cout << "char : " << ch << endl;
//     }
// };
// int main() {
//     Print p1;
//     p1.show(101);  // compiler automatically detects which show to call based on type of input
//     return 0;
// }


                                                                                                  //Run Time polymorphism
//eg.Function Overriding
class Parent {
public:
    void getInfo() {
        cout << "parent class\n";
    }
};
class Child : public Parent {
public:
    void getInfo() {
        cout << "child class\n";
    }
};
int main() {
    Child c1;
    //c1.getInfo();  // Output should have been parent class, but output is child class. So child class is overridding parent class
    return 0;
}



