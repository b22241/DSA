#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//brute force appraoch O(n3*log(triplets))
// vector<vector<int>> triplets(vector<int> &vec){
//     set<vector<int>> s; //set stores unique triplets
//     vector<vector <int>> ans;
//     for(int i=0;i<vec.size();i++){
//         for(int j=i+1;j<vec.size();j++){
//             for (int k=j+1;k<vec.size();k++){
//                 if(vec[i]+vec[j]+vec[k]==0){
//                     vector<int> trip={vec[i],vec[j],vec[k]};
//                     sort(trip.begin(),trip.end());

//                     if(s.find(trip)==s.end())
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

//optimied O(n2*log(triplets))
// vector<vector<int>> triplets(vector<int> &vec){
// int n = vec.size();
// vector<vector<int>> ans;
// set<vector<int>> uniqueTriplets;
// for (int i = 0; i < n; i++) {
//     int tar = -vec[i];
//     set<int> s;

//     for (int j = i + 1; j < n; j++) {
//         int third = tar - vec[j];

//         if (s.find(third) != s.end()) {
//             vector<int> trip = {vec[i], vec[j], third};
//             sort(trip.begin(), trip.end());
//             uniqueTriplets.insert(trip);
//         }

//         s.insert(vec[j]);
//     }
// }
// }

//most optimised O(nlogn+n2)
vector<vector<int>> threeSum(vector<int>& vec) {
    int n = vec.size();
    vector<vector<int>> ans;
    sort(vec.begin(),vec.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && vec[i] == vec[i - 1]) continue;

        int j = i + 1, k = n - 1;

        while (j < k) {
            int sum = vec[i] + vec[j] + vec[k];

            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                ans.push_back({vec[i], vec[j], vec[k]});
                j++;
                k--;
            }
        }
    }
    return ans;
}


int main(){
    vector<int> vec={-1,0,1,2,-1,-4};
    vector<vector<int>> result = threeSum(vec);
    for (const auto& quadruplet : result) {
        cout << "[";
        for (size_t i = 0; i < quadruplet.size(); i++) {
            cout << quadruplet[i] << (i == quadruplet.size() - 1 ? "" : ", ");
        }
        cout << "]\n";
    }
    return 0;
}




