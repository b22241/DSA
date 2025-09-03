#include<stdio.h>

void display(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//merging two sorted arrays

void merge_sort(int arr1[], int size1, int arr2[], int size2, int arr3[])
{
    int k=0;
    int i=0;
    int j=0;
    while(i<size1 && j<size2)
    {
        if (arr1[i]<=arr2[j])
        {
            arr3[k]=arr1[i];
            i++;
            k++;
        }
        else
        {
            arr3[k]=arr2[j];
            j++;
            k++;
        }
    }
    while (i < size1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
}

// merging 2 sorted arrays of a single array
void merge2_sort(int arr[],int size,int index,int new_arr[])
{
    int i=0;
    int j=index+1;
    int k=0;
    while(i<=index && j<size)
    {
        if(arr[i]>=arr[j])
        {
            new_arr[k]=arr[j];
            j++;
        }
        else
        {
            new_arr[k]=arr[i];
            i++;
        } 
        k++;   
    }
    while (i <=index)
    {
        new_arr[k] = arr[i];
        i++;
        k++;
    }
    while (j < size)
    {
        new_arr[k] = arr[j];
        j++;
        k++;
    }
}


int main()
{
    // int arr1[]={-66,-27,8,18,19,22,90};
    // int arr2[]={1,6,9,11};
    // int size1 = sizeof(arr1) / sizeof(arr1[0]);
    // int size2 = sizeof(arr2) / sizeof(arr2[0]);
    // int size3 = size1 + size2;
    // int arr3[size3];

    int arr[]={7,15,18,2,8,10,11,15,60,65};
    int size = sizeof(arr) / sizeof(arr[0]);
    int new_arr[size];
    int index=2;

    // printf("Two sorted arrays before merging\n");
    // display(arr1,size1);
    // display(arr2,size2);
   
    // merge_sort(arr1,size1,arr2,size2,arr3);
    // printf("Final sorted array after merging\n");
    // display(arr3,size3);
    merge2_sort(arr, size,index,new_arr);
    display(new_arr,size);
    return 0;


}

   