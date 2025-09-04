#include <iostream>
#include <climits>
#include <vector>
#include <numeric>  // For accumulate
#include <algorithm> // For max_element
#include <algorithm> // For sort function
using namespace std;

int fac(int n){
    if(n==0){
        return 1;
    }
    return n*fac(n-1);
}

int binary(int n){
    int binary=0;
    int i=1;
    while(n>0){
        int rem=n%2;
        binary=binary+rem*i;
        i=i*10;
        n=n/2;
    }
    return binary;
}

int decimal(int n){
    int num=0;
    int i=0;
    while(n>0){
        num=num+(n%10)*(1 << i);
        i++;
        n=n/10;
    }
    return num;
}

void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - i - 1]);
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; 
}

void subArray(int arr[], int n) {    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = i; k <= j; k++) {
                cout << arr[k];
            }
            cout << " ";  
        }
        cout<<endl;
    }
}                                          

void kadaneAlgorithm(int arr[], int n) {
    int sum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > maxSum) {
            maxSum = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }

    cout << "Maximum Subarray Sum: " << maxSum << endl;
}

int mooreAlgorithm(int arr[], int n) {
    int candidate = arr[0], freq = 1;

    // Phase 1: Find the potential majority element
    for (int i = 1; i < n; i++) {
        if (arr[i] == candidate) {
            freq++;
        } else {
            freq--;
            if (freq == 0) {
                candidate = arr[i];
                freq = 1;
            }
        }
    }

    // Phase 2: Verify if the candidate appears more than n/2 times
    freq = 0; 
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) {
            freq++;
        }
    }

    if (freq > n / 2) {
        return candidate;
    }

    return -1; // No majority element found
}

int maxProfit(int arr[], int n) {
    int bestBuy = arr[0]; 
    int maxProfit = 0;       
        for (int i = 1; i < n; i++){
            if(arr[i]>bestBuy){
                maxProfit = max(maxProfit, arr[i]-bestBuy);
            }
            bestBuy = min(bestBuy, arr[i]);
    }
     return maxProfit;
}

vector<int> productSelf(int arr[], int n) {
    vector<int> product; 

    for (int i = 0; i < n; i++) {
        int p = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                p = p*arr[j];   
            }
        }
        product.push_back(p); 
    }
    return product;
}

vector<int>productSelf_(int arr[],int n){
    vector<int> prefix(n); 
    vector<int> suffix(n);
    vector<int> product(n);
    prefix[0]=arr[0];
    suffix[n-1]=arr[n-1];
    for (int i=1;i<n;i++){
        prefix[i]=prefix[i-1]*arr[i];
    }

    for (int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]*arr[i];
    }

    for (int i = 0; i < n; i++) {
        product[i] = (i > 0 ? prefix[i - 1] : 1) * (i < n - 1 ? suffix[i + 1] : 1);
    }

    return product;

}

vector<int>productSelf__(int arr[],int n){
    vector<int>product(n,1);
    int prefix=1;
    for (int i=1;i<n;i++){
        product[i]=product[i-1]*arr[i-1];
    }
    int suffix=1;
    for (int i=n-2;i>=0;i--){
        suffix=suffix*arr[i+1];
        product[i]=product[i]*suffix;
    }
    return product;
}

int BinarySearch(const vector<int>& arr, int target) {
    int start = 0; int end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int recursiveBinarySearch(const vector<int>& arr, int target, int start, int end) {
    if (start > end) {
        return -1; 
    }
    int mid = start + (end - start) / 2;
    if (target > arr[mid]) {
        return recursiveBinarySearch(arr, target, mid + 1, end);
    } else if (target < arr[mid]) {
        return recursiveBinarySearch(arr, target, start, mid - 1);
    } else {
        return mid;
    }
}

int rotatedSortedArray(const vector<int> &arr,int target,int start,int end){
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        // Check if the left half is sorted
        if (arr[start] <= arr[mid]) { 
            if (arr[start] <= target && target < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        // Otherwise, the right half must be sorted
        else { 
            if (arr[mid] < target && target <= arr[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int peakIndex(const vector<int>& arr, int start, int end) {
    if (start >= end) { 
        return start; 
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] > arr[mid + 1]) {
        return peakIndex(arr, start, mid); 
    } else {
        return peakIndex(arr, mid + 1, end); 
    }
}

int single_element_in_sorted_array(const vector<int> &arr) 
{
    int st = 0;
    int end = arr.size() - 1;

while (st <= end) {
  int mid = st + (end - st) / 2;

  if ((mid == 0 || arr[mid] != arr[mid - 1]) && (mid == arr.size() - 1 || arr[mid] != arr[mid + 1])) {
      return arr[mid];
  }
  if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 == 1 && arr[mid] == arr[mid - 1])) {
      st = mid + 1;  // Move right
  } else {
      end = mid - 1; // Move left
  }
}

return -1; // Should never reach here
}

bool isValid(const vector<int> &arr, int n, int m, int maxallowedpages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) { 
        if (arr[i] > maxallowedpages) {
            return false;
        }

        if (pages + arr[i] <= maxallowedpages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
            if (students > m) return false;
        }
    }

    return true; // Ensuring function returns a value
}

int book_allocation(const vector<int> &arr, int n, int m) {
    if (m > n) return -1;

    int sum = accumulate(arr.begin(), arr.end(), 0);
    int st = *max_element(arr.begin(), arr.end()); 
    int end = sum;
    int ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (isValid(arr, n, m, mid)) { 
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1; 
        }
    }

    return ans; 
}

bool ispossible(const vector<int> &arr, int n,int m, int time) {
    int painters = 1;
    int paint_time = 0;
    for (int i=0;i<n;i++){
        if(arr[i]>time) return false;
        if (paint_time + arr[i] <= time) {
            paint_time += arr[i];
        } else {
            painters++;
            paint_time= arr[i];
            if (painters > m) return false;
        }
    }
    return true;
}

int painters_partition(const vector<int> &arr, int n,int m){
    int min_time= *max_element(arr.begin(), arr.end()); 
    int max_time = accumulate(arr.begin(), arr.end(), 0);
    int start=min_time;
    int end=max_time;
    int ans;
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (ispossible(arr, n, m, mid)) { 
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1; 
        }
    }
    return ans; 
}

bool possible_distance(const vector<int> &arr, int mid,int cows){
    int last_position=arr[0];
    int cows_placed=1;
    for (int i=1;i< arr.size();i++)
    {
        if ((arr[i]-last_position)>=mid)
        {
            last_position=arr[i];
            cows_placed++;
            if (cows_placed==cows) return true;
        }
    }    
    return false;
}

int aggresive_cows(vector<int> &arr,int cows){
    sort(arr.begin(), arr.end());
    int start = 1; // Minimum possible distance
    int end = arr[arr.size() - 1] - arr[0]; // Maximum possible distance
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(possible_distance(arr,mid,cows)){
            start=mid+1;
            ans=mid;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}

// int bubble_sort(vector<int> &arr){
//     for( int i=0;i<arr.size(),i++){
//         for ( int j=i;j<arr.size()-i-1;j++){
//             if (arr[j+1]>arr[j]);{
//                 swap(arr[j],arr[j+1]);
//             }
//         }
//     }
//     return arr[];
// }


int main() {
    vector<int> arr = {1,2,8,4,9};
    int n=arr.size();
    int cows=3;
    // cout<<fac(3);
    // cout<<binary(12);
    // cout<<decimal(1100);
    // reverseArray(arr.data(), n);
    // subArray(arr.data(),n);
    // kadaneAlgorithm(arr.data(),n);
    return 0;
}


