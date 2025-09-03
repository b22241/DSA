#include <stdio.h>
#include <stdlib.h>
 

void display(int arr[], int n) {
    // Code for Traversal
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index) {
    // code for Insertion
    if (size >= capacity) {
        return -1;
    }
    for (int i = size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main() {
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 1;

    printf("Array before insertion:\n");
    display(arr, size);
    
    indInsertion(arr, size, element, 100, index);
    size += 1;

    printf("Array after insertion:\n");
    display(arr, size);

    printf("First element: %d\n", arr[0]);

    return 0;
}




// #include <stdio.h>
// #include <stdlib.h>

// void display(int arr[], int n)
// {
//     // Code for Traversal
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// void indDeletion(int arr[], int size, int index)
// {
//     // code for Deletion
//     for (int i = index; i < size-1; i++)
//     {
//         arr[i] = arr[i + 1];
//     }  
// }

// int main()
// {
    
//     int arr[100] = {7, 8, 12, 27, 88};
//     int size = 5, element = 45, index = 0;
//     printf("Arrary before deletion:\n");
//     display(arr, size);
//     indDeletion(arr, size, index);
//     size -= 1;
//     printf("Arrary after deletion:\n");
//     display(arr, size);
//     return 0;
// }

 