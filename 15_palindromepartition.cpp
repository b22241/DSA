#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;


//palindrome partitioning


bool isPalindrome(string s){
    string s2=s;
    reverse(s2.begin(),s2.end());
    return s==s2;
}
void getpalindrome(string s,vector<vector<string>> &ans,vector<string> &partition){
    if (s.size()==0){
        ans.push_back(partition);
        return;
    }
    for (int i=0;i<s.size();i++){
        string part=s.substr(0,i+1);

        if(isPalindrome(part)){
            partition.push_back(part);
            getpalindrome(s.substr(i+1),ans,partition);
            partition.pop_back();
        }
    }

}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>partition;
        getpalindrome(s,ans,partition);
        return ans;
        }

        

int main() {
    string s = "aab";
    vector<vector<string>> result = partition(s);
    for (auto vec : result) {
        cout << "[ ";
        for (string num : vec) {
            cout << num << ",";
        }
        cout << "]\n";
    }
    return 0;
}
        