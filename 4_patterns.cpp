#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

void sum_of_digits(int num){
    int ans = 0;
    while (num > 0)
    {
        ans = ans + num % 10;
        num = num / 10;
    }
    cout << ans;
}

int factorial(int n){
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

void n_C_r(int n, int r){
    cout << factorial(n) / (factorial(r) * factorial(n - r));
}

void decimal_to_binary(int num){
    stack<int> ans;
    while (num > 0)
    {
        ans.push(num % 2);
        num = num / 2;
    }
    while (!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }
}

void binary_to_decimal(int bin){
    int num = 0, base = 1;
    while (bin > 0)
    {
        int last_digit = bin % 10;
        num = num + last_digit * base;
        base = base * 2;
        bin = bin / 10;
    }
    cout << num;
}

void reverse_array(int arr[], int n){
    for (int i = 0; i < n / 2; i++){
        int temp = arr[i];
       swap(arr[i],arr[n - i - 1]);
    }
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void subarr_of_arr(int arr[], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = k + 1; i <= n; i++) { 
            for (int j = k; j < i; j++) {  
                cout << arr[j];
            }
            cout << ","; 
        }
    }
}

//brute force method to calcule max sum of subarray
void sum_of_subarr(int arr[], int n) {
    int max_sum=INT32_MIN;
    for (int k = 0; k < n; k++) {
        for (int i = k + 1; i <= n; i++) { 
            int sum=0;
            for (int j = k; j < i; j++) {  
               sum=sum+arr[j];
            }
           max_sum=max(sum,max_sum);
        }
    }
    cout<<max_sum;
}

//Kadane's Algorithm
void kadanes_algo(int arr[],int n){
    int max_sum = arr[0];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        max_sum=max(sum,max_sum);
        sum=max(sum,0);
    }
    cout << max_sum;
}

//find pair whose sum is equal to target sum
void pair_sum(int arr[],int n){
    unordered_map<int,int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;  // auto-increments count (default is 0)
    }
    int maxFreq = 0;
    int maxElem = -1;
     for (auto p : freq) {
        if (p.second > maxFreq) {
            maxFreq = p.second;
            maxElem = p.first;
        }
    }
    cout<<maxElem;
}

void binary_seach(vector<int>arr,int key){
    int st=0;int end=arr.size()-1;
    while(st<end){
        int mid=st+(end-st)/2;
        if(key>arr[mid]){
            st=mid+1;
        }
        else if(key<arr[mid]){
            end=mid-1;
        }
        else{
            cout<<mid;
            return;
           }
    }
}

//recursive binary_seach
void recursive_binary_seach(vector<int>arr,int st, int end,int key){
    while(st<=end){
        int mid=st+(end-st)/2;
        if(key>arr[mid]){
            return recursive_binary_seach(arr,mid+1,end,key);
        }
        else if(key<arr[mid]){
            return recursive_binary_seach(arr,st,mid-1,key);
        }
        else{
            cout<<mid;
            return;
           }
    }
}

//seach in rotated arrary
void rotated_binary_seach(vector<int>arr,int st, int end,int key){
    while(st<=end){
        int mid=st+(end-st)/2;
        if(key<arr[mid]){
            return recursive_binary_seach(arr,mid+1,end,key);
        }
        else if(key<arr[mid]){
            return recursive_binary_seach(arr,st,mid-1,key);
        }
        else{
            cout<<mid;
            return;
           }
    }
}

void peak_index_mountain_array(vector<int>arr,int st,int end){
    int mid;
    while(st<=end){
        mid=st+(end-st)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]){
            return peak_index_mountain_array(arr,mid+1,end);
        }
        if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1]){
            return peak_index_mountain_array(arr,st,mid-1);
        }
        else{
            cout<<mid;
            return;
        }
    }
}

//O(n)
void singleNonDuplicate(vector<int>& nums) {
        stack<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (!s.empty() && s.top() == nums[i]) {
                s.pop();
            } else {
                s.push(nums[i]);
            }
        }
         cout<< s.top(); // Only one unique element remains
    }

//O(logn) 
void singleNon_duplicate_element(vector<int>& arr, int st, int end) {
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (st == end) {
            cout << arr[mid];
            return;
        }
        // Make sure mid is not out of bounds for -1 and +1 access
        if (mid > 0 && arr[mid - 1] == arr[mid]) {
            if ((mid - st) % 2 == 0) {
                return singleNon_duplicate_element(arr, st, mid - 2);
            } else {
                return singleNon_duplicate_element(arr, mid + 1, end);
            }
        }
        if (mid < arr.size() - 1 && arr[mid] == arr[mid + 1]) {
            if ((mid - st) % 2 == 0) {
                return singleNon_duplicate_element(arr, mid + 2, end);
            } else {
                return singleNon_duplicate_element(arr, st, mid - 1);
            }
        }
    }
}

//book allocation problem
bool valid_book(vector<int>& arr, int n, int m, int maxAllowedPages) {
    int students = 1, pages = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxAllowedPages)
            return false;
        if (pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
    }
    return students > m ? false : true;
}
void allocateBooks(vector<int>& arr, int n, int m) {
    if (m > n) cout<< -1; 

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];  
    }
    int start = 0, end = sum, result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (valid_book(arr, n, m, mid)) {
            result = mid;
            end = mid - 1; 
        } else {
            start = mid + 1;
        }
    }
   cout<<result;
}

//painter's partition problem
bool valid_time(vector<int>& arr, int n, int m, int max_allowed_time) {
    int painters = 1, time = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_allowed_time)
            return false;
        if (time + arr[i] <= max_allowed_time) {
            time += arr[i];
        } else {
            painters++;
            time = arr[i];
        }
    }
    return painters > m ? false : true;
}
void allocate_time(vector<int>& arr, int n, int m) {
    if (m > n) cout<< -1; 

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];  
    }
    int start = 0, end = sum, result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (valid_time(arr, n, m, mid)) {
            result = mid;
            end = mid - 1; 
        } else {
            start = mid + 1;
        }
    }
   cout<<result;
}

//aggressive cows problem
bool valid_distance(vector<int>& arr, int n, int cows, int min_allowed_distance) {
    int count = 1;
    int last_position = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - last_position >= min_allowed_distance) {
            count++;
            last_position = arr[i];
        }
        if (count >= cows) return true;
    }
    return false;
}
void aggressive_cows(vector<int>& arr, int n, int cows) {
    if (cows > n) {
        cout << -1;
        return;
    }
    sort(arr.begin(), arr.end());
    int start = 1;
    int end = arr[n - 1] - arr[0];
    int result = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (valid_distance(arr, n, cows, mid)) {
            result = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << result;
}



int main()
{
    // sum_of_digits(146);
    // n_C_r(8,2);
    // decimal_to_binary(42);
    // binary_to_decimal(101010);
    // int arr[] = {1, 2, 3};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // reverse_array(arr, n);

    //int arr[] = {1, 2, 3,4,5};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // subarr_of_arr(arr,n);

    // int arr[] = {3,-4,5,4,-1,7,-8};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // sum_of_subarr(arr,n);

    // int arr[] = {3,-4,5,4,-1,7,-8};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // kadanes_algo(arr,n);

    // int arr[] = {2,7,11,15};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int key=17;
    // pair_sum(arr,n,key);

    // int arr[] = {2,2,1,1,1,2,2};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // pair_sum(arr,n);

    // vector<int>arr={-1,0,1,3,5,7,8,9};
    // int key=7;
    // binary_seach(arr,key);

    // vector<int>arr={-1,0,1,3,5,7,8,9};
    // int key=9;
    // recursive_binary_seach(arr,0,arr.size()-1,key);

    // vector<int>arr={0,3,8,9,10,5,2};
    // int st=0;
    // int end=arr.size()-1;
    // peak_index_mountain_array(arr,st,end);

    // vector<int>arr={1,1,2,3,3,4,4,8,8};
    // singleNonDuplicate(arr);

    
    // vector<int>arr={1,1,2,3,3,4,4,8,8};
    // int st=0;
    // int end=arr.size()-1;
    // singleNon_duplicate_element(arr,st,end);

    // vector<int> books = {10, 20, 30, 40};
    // int n = books.size();
    // int m = 2;  // Number of students
    // allocateBooks(books, n, m);

    // vector<int> arr = {40,30,10,20};
    // int n = arr.size();
    // int m = 2;  // Number of painters
    // allocateBooks(arr, n, m);

    vector<int> arr = {1,2,8,4,9};
    int n = arr.size();
    int cows = 3;  // Number of cows
    aggressive_cows(arr, n, cows);





}