#include<stdio.h>
#include<stdlib.h>


void display(int arr[], int n){
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");   
}
int binarySearch(int arr[], int size, int element) 
{
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == element) {
            return mid;  // Element found, return the index
        } else if (arr[mid] < element) {
            low = mid + 1;  // Search in the right half
        } else {
            high = mid - 1;  // Search in the left half
        }
    }
    return -1;
}

int main()
{
    //code for binary search
    int arr[] = {7, 8, 12, 27,43,45,56};
    int size = sizeof(arr)/sizeof(int), element = 27;
    int searchIndex = binarySearch(arr, size, element);
   if (searchIndex != -1) 
    {
        printf("Element %d found at index %d\n", element, searchIndex);
    }
     else 
    {
        printf("Element %d not found\n", element);
    }

    return 0;
}

