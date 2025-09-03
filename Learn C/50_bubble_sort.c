#include <stdio.h>
#include <stdlib.h>

// Function to display the array
void display(int arr[], int n) {
    for (int l = 0; l < n; l++) {
        printf("%d ", arr[l]);
    }
    printf("\n");
}

// Function to sort the array
void bubblesort(int arr[]) 
{
    int size = 6;
    for (int i = 0; i < size-1; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[i] > arr[j]) 
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() 
{
    int arr[100] = {7,0,4,3,6,1};
    int size = 6;
    printf("Your array before sorting time is\n");
           display(arr,6);
    for(int i=1;i<size;i++)
    {
        for(int j=1;j<size-i-1;j++)
        {
           bubblesort(arr);     
        }   
    }
    printf("Your array after sorting time is\n");
           display(arr,6);
    return 0;
}

