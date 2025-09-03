#include<algorithm>
#include <iostream>
#include<string>
using namespace std;
#include<vector>


//object oriented programming(OOPS)
//converting real life scenerios in codeing language
//objects are entitites in real world ..eg->pen,laptop,book
//class is like a blueprint of these entitis ..eg->how car looks like, class of students, 

class Teacher{
    //properties /attributes
private:
    double salary;   
    
    public:
    Teacher(){
        dept="csee";
    }
public:
    string name;
    string dept;
    string subject;

    //methods/member functions
    void changeDept(string newDept){
        dept=newDept;
    }
    
    //setter
    void setSalary(double s){
        salary=s;
    }
    //getter
    double getSalary(){
        return salary;
    }
};

int main(){
    Teacher t1;
    t1.name="ram";
    t1.subject="c++";

    cout<<t1.dept;
}