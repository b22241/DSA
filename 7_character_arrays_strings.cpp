#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cctype>  // for tolower()
using namespace std;
#include <algorithm> // Add this include for std::reverse


//character arrays  advanced version of strings
// int main(){
//     char str[]={"hello"};
//     cout<<strlet(str);   5 
//     cin.getline(str,100,"$");
//     for(char ch:str){
//         cout<<ch<<" ";
//     }
// }

//strings  advanced version of char arr, and better 
//dynamic in nature, can be modified in runtime but character arrarys can't be modified
// int main(){
//     string str1="apma collage";
//     string str2="ram ram ";
//     cout<<str1+str2<<endl;
//     cout<<(str1==str2);   1   not in char arr
//     cout<<(str1>str2);  1   a>r(lexicographic order)
//     cout<<str1.length();
//     reverse(str1.begin(),str1.end());
// }

//Palindrome for string
// bool isPalindrome(string s) {
//     int st = 0, end = s.length() - 1;
//         while (st < end) {
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

// string removeOccurrences(string s, string part) {
//     while (s.length() > 0 && s.find(part) < s.length()) {
//         s.erase(s.find(part), part.length());
//     }
//     return s;
// }

//reverse words in string
// void reverseString(string& part){
//     reverse(part.begin(), part.end());
//     int i=0;
//     string ans="";
//     for(int i=0;i<part.length();i++){
//         string word="";
//         while(i<part.length() && part[i]!=' '){
//             word+=part[i];
//             i++;
//         }
//         reverse(word.begin(),word.end());
//         if(word.length()>0){
//             ans=ans+" "+word;
//         }
//     }
//     cout<<ans.substr(1);
// }


int stringCompression(string &chars) {
    int idx = 0;
    for (int i = 0; i < chars.length();) {
        char ch = chars[i];
        int count = 0;
        while (i < chars.length() && chars[i] == ch) {
            count++;
            i++;
        }
        chars[idx++] = ch;  // store the character
        if (count > 1) {
            string str = to_string(count);
            for (char dig : str) {
                chars[idx++] = dig;  // store each digit of count
            }
        }
    }
    return idx;  // return new length
}

int main() {
    string s = "daabcbaabcbc";
    string part = "abc bb";    
    // reverseString(part);
    // int newLength = stringCompression(s);
    // cout << "Compressed: ";
    // for (int i = 0; i < newLength; i++) {
    //     cout << s[i];
    // }
    // cout << removeOccurrences(s, part) << endl;  // Expected output: "dab"
}