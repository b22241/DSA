#include<stdio.h>

void display(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void countsort(int arr1[],int size1,int max_element)
{
    int size2=max_element+1;
    int arr2[]={0,0,0,0,0,0,0,0,0,0};
    int arr3[size1];
    int k=0;
    for(int i=0;i<size1;i++)
    {
        arr2[arr1[i]]++;
    }
    for(int j=0;j<size2;j++)
    {
        if(arr2[j]==1)
        {
            arr3[k]=j;
            k++;
        }
        if(arr2[j]==2)
        {
            arr3[k]=j;
            arr3[k+1]=j;
        }
    }
}

int main()
{
    int arr1={3,1,9,7,1,2,4};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int max_element=9;
    printf("Arrary before sorting\n");
    display(arr1,size1);

    countsort(arr1,size1,max_element);
    printf("Arrary after sorting\n");
    display(arr3,size1);
    return 0;
}