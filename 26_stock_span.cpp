#include<algorithm>
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

//O(n2)
// vector<int> stock_span(vector<int>v){
//     vector<int>span;
//     for (int i=0;i<v.size();i++){
//         int cnt=0;
//         for(int j=i;j>=0;j--){
//             if(v[i]>=v[j]){
//                 cnt++;
//             }
//             else{
//                 break;
//             }
//         }
//         span.push_back(cnt);
//     }
//     return span;
// }

//O(n)
// vector<int> stock_span(vector<int>v){
//         vector<int> ans(v.size(), 0);
//         stack<int> s;
//         for (int i = 0; i < v.size(); i++) {
//             while (s.size() > 0 && v[s.top()] <= v[i]) {
//                 s.pop();
//             }
    
//             if (s.empty()) {
//                 ans[i] = i + 1;
//             } else {
//                 ans[i] = i - s.top();  // i - prevHigh
//             }
    
//             s.push(i);
//         }
//         return ans;
// }


// int main(){
//     vector<int> v = {100, 80, 60, 70, 60, 75, 85};
//     vector<int> result = stock_span(v);

//     for (int x : result) {
//         cout << x << " ";
//     }
//     cout << endl;
//     return 0;
// }

//O(n2)
// vector<int> next_greater_element(vector<int> v) {
//     vector<int> ans(v.size(), -1); 
//     for (int i = 0; i < v.size(); i++) {
//         for (int j = i + 1; j < v.size(); j++) {
//             if (v[j] > v[i]) {
//                 ans[i] = v[j];
//                 break; // Exit inner loop
//             }
//         }
//     }
//     return ans;
// }

// //O(n)
// vector<int> next_greater_element(vector<int> v) {
//     vector<int> ans(v.size(), -1); 
//     stack<int> s;

//     for (int i = v.size() - 1; i >= 0; i--) {
//         while (!s.empty() && s.top() <= v[i]) {
//             s.pop();
//         }
//         if (!s.empty()) {
//             ans[i] = s.top();
//         }

//         s.push(v[i]);
//     }

//     return ans;
// }


// int main(){
//     vector<int> v={6,8,0,1,3};
//     vector<int> result = next_greater_element(v);

//     for (int x : result) {
//         cout << x << " ";
//     }
//     cout << endl;

    
// }


// vector<int>previous_smaller_element(vector<int> v){
//     stack<int>s;
//     vector<int>ans(v.size(), -1);
//     for(int i=0;i<v.size();i++){
//         while (!s.empty() && s.top() >= v[i]) {
//                         s.pop();
//                     }
//                     if (!s.empty()) {
//                         ans[i] = s.top();
//                     }
            
//                     s.push(v[i]);
//                 }
//                 return ans;

//     }

// int main(){
//     vector<int>v={3,1,0,8,6};
//     vector<int>result=previous_smaller_element(v);
//     for (int x:result){
//         cout<<x<<" ";
//     }
//     cout<<endl;
// }



int min_rectangle_area(vector<int> v) {
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        int area = 0;
        int j = i;
        int k = i;
        // Expand to the right
        while (v[j + 1] >= v[i] && j + 1 < v.size()) {
            j++;
        }
        // Expand to the left
        while ( v[k - 1] >= v[i]  && k - 1 >= 0 ) {
            k--;
        }
        area = v[i] * (j - k + 1);
        ans = max(ans, area);
    }

    return ans;
}

int main() {
    vector<int> v = {2, 1, 6, 6, 2, 4};
    cout << min_rectangle_area(v);
}


