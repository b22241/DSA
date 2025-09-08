#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;


// vector<vector<int>> triplets(vector<int> &vec){              //brute force appraoch O(n3*log(triplets))
//     set<vector<int>> s; //set stores unique triplets
//     vector<vector <int>> ans;
//     for(int i=0;i<vec.size();i++){
//         for(int j=i+1;j<vec.size();j++){
//             for (int k=j+1;k<vec.size();k++){
//                 if(vec[i]+vec[j]+vec[k]==0){
//                     vector<int> trip={vec[i],vec[j],vec[k]};
//                     sort(trip.begin(),trip.end());
//                     if(s.find(trip)==s.end())          //O(logn)
//                     {
//                         s.insert(trip);
//                         ans.push_back(trip);
//                     }
//                 }
//             }
//         };
//     }
//     return ans;
// }

// vector<vector<int>> threeSum(vector<int>& vec) {              //O(n2*log(triplets))
//     vector<vector<int>> ans;
//     set<vector<int>> uniqueTriplets; // to avoid duplicates
//     int n = vec.size();
//     for(int i = 0; i < n; i++) {
//         set<int> s; 
//         for(int j = i + 1; j < n; j++) {
//             int target = -(vec[i] + vec[j]);
//             if(s.find(target) != s.end()) {       // found triplet
//                 vector<int> trip = {vec[i], vec[j], target};
//                 sort(trip.begin(), trip.end());
//                 uniqueTriplets.insert(trip);
//             }
//             s.insert(vec[j]);
//         }
//     for(auto &trip : uniqueTriplets) {
//         ans.push_back(trip);
//     }
//     return ans;
//     }
// }
    
// vector<vector<int>> optimised(vector<int>& vec) {             //most optimised O(nlogn+n2)
//     int n = vec.size();
//     vector<vector<int>> ans;
//     sort(vec.begin(), vec.end());
//     for (int i = 0; i < n; i++) {
//         if (i > 0 && vec[i] == vec[i - 1]) continue;  // skip duplicates
//         int first = vec[i];
//         int j = i + 1;
//         int k = n - 1;
//         while (j < k) {
//             int sum = first + vec[j] + vec[k];
//             if (sum == 0) {
//                 ans.push_back({first, vec[j], vec[k]});
//                 j++;
//                 k--;
//                 while (j < k && vec[j] == vec[j - 1]) j++;  // skip dup
//                 while (j < k && vec[k] == vec[k + 1]) k--;  // skip dup
//             }
//             else if (sum < 0) {
//                 j++;
//             } else {
//                 k--;
//             }
//         }
//     }
//     return ans;
// }


int main(){
    vector<int> vec={-1,0,1,2,-1,-2};
    // vector<vector<int>> result = optimised(vec);
    // for (auto triplet : result) {
    //     for (auto val : triplet) cout << val << " ";
    //     cout << endl;
    // }
    // return 0;
}




