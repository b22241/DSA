#include <bits/stdc++.h>
using namespace std;


//O(nlogn)
//O(n)-space complexity
//MERGE SORT- divide till last and merge them in sorted order
// but quicsort has O(1) space complexity, though quick sort has time complxity O(n2) in worst case
void merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[idx + st] = temp[idx];
    }
}

void mergeSort(vector<int> &arr, int st, int end) {
    if (st < end);

    int mid = st + (end - st) / 2;
    mergeSort(arr, st, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, st, mid, end);
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 6, 3};
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
