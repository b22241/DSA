#include <bits/stdc++.h>
using namespace std;

bool isValid(string str) {
    stack<char> st;
    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;  
            if ((c == ')' && st.top() != '(') ||
                (c == ']' && st.top() != '[') ||
                (c == '}' && st.top() != '{')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s = "()[]{}";
    cout << isValid(s);
}
