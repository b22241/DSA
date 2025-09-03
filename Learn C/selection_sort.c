#include<stdio.h>

void display(int arr[], int n) {
    for (int l = 0; l < n; l++) {
        printf("%d ", arr[l]);
    }
    printf("\n");
}

void selectionsort(int arr[], int size)
{
    int i, j, minIndex, temp;
    for (i = 0; i < size-1; i++)
    {
        minIndex = i;
        for (j = i+1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        if (minIndex != i)
        {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main()
{
    int arr[9]={11,8,7,1,3,4,100,2,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("Array before sorting \n");
    display(arr, size);
    selectionsort(arr, size);
    printf("Array after sorting \n");
    display(arr, size);
    
    return 0;
}
