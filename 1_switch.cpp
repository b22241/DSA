#include<bits/stdc++.h>
using namespace std;

void sayDigit(int n){
    vector<string> arr = {"ero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string num =to_string(n);
    for(char ch:num){
        cout<<arr[ch-'0']<<" ";
    }
}
int main(){
    // int num=22;

    // switch(num){
        
    //     case 1:cout<<"first";
    //     break;

    //     case 2:cout<<"second";
    //     break;

    //     default: cout<<"default case";
    // }
    // int n=4;
    // int *ptr=&n;
    // cout<<*ptr;

//    int num = 5;
//    int a = num;
//    cout << "a before " << a << endl;
//    a++;
//    cout << "a after " << a << endl;

sayDigit(412);

}
