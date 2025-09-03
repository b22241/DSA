#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cctype>  // for tolower()
using namespace std;


//character arrays
// int main(){
//     char str[]={"hello"};
//     // cin.getline(str,100);
//     for(char ch:str){
//         cout<<ch<<" ";
//     }
// }


//strings
//dynamic in nature, can be modified in runtime but character arrarys can't be modified
// int main(){
//     string str1="apma collage";
//     string str2="ram ram ";
//     cout<<str1+str2<<endl;
//     cout<<str1.length();
//     //reverse(str1.begin(),str1.end());

// }

//Palindrome for string
// bool isPalindrome(string s) {
//     int st = 0, end = s.length() - 1;

//     while (st < end) {
//         // Skip non-alphanumeric characters
//         if (!isalnum(s[st])) {
//             st++;
//             continue;
//         }
//         if (!isalnum(s[end])) {
//             end--;
//             continue;
//         }

//         // Compare characters (case insensitive)
//         if (tolower(s[st]) != tolower(s[end])) {
//             return false;
//         }

//         st++;
//         end--;
//     }

//     return true;
// }

// int main() {
//     string str = "A man, a plan, a canal: Panama";
//     cout << (isPalindrome(str) ? "True" : "False") << endl;

//     return 0;
// }


string removeOccurrences(string s, string part) {
    while (s.length() > 0 && s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main() {
    string s = "daabcbaabcbc";
    string part = "abc";
    
    cout << removeOccurrences(s, part) << endl;  // Expected output: "dab"

    return 0;
}