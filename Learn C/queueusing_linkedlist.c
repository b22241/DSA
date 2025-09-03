#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// sbse akhiri me element add hoga
struct Node * enqueue(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->data = data;
    ptr->next = NULL;
    return head;
}

// sbse phle vala element niklega
struct Node * denqueue(struct Node *head)
{
    struct Node * p = head;
    head=head->next;
    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Link third and fourth nodes
    fourth->data = 66;
    fourth->next = fifth;

    // Terminate the list at the third node
    fifth->data = 2;
    fifth->next = NULL;

    printf("Linked list before denqueue\n");
    linkedListTraversal(head);
    //head = enqueue(head);
    head = denqueue(head);
    head = denqueue(head);
    head = denqueue(head);

    printf("\nLinked list after denqueue\n");
    linkedListTraversal(head);
    return 0;
}





// Method 2
// #include <stdio.h>
// #include <stdlib.h>

// struct Node *f = NULL;
// struct Node *r = NULL;

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// void linkedListTraversal(struct Node *ptr)
// {
//     printf("");
//     while (ptr != NULL)
//     {
//         printf(" %d", ptr->data);
//         ptr = ptr->next;
//     }
//     printf("\n");
// }

// void enqueue(int val)
// {
//     struct Node *n = (struct Node *)malloc(sizeof(struct Node));
//     if (n == NULL)
//     {
//         printf("Queue is Full");
//     }
//     else
//     {
//         n->data = val;
//         n->next = NULL;
//         if (f == NULL)
//         {
//             f = r = n;
//         }
//         else
//         {
//             r->next = n;
//             r = n;
//         }
//     }
// }

// int dequeue()
// {
//     int val = -1;
//     struct Node *ptr = f;
//     if (f == NULL)
//     {
//         printf("Queue is Empty\n");
//     }
//     else
//     {
//         f = f->next;
//         val = ptr->data;
//         free(ptr);
//     }
//     return val;
// }

// int main()
// {
//     enqueue(34);
//     enqueue(4);
//     enqueue(7);
//     enqueue(17);
//     enqueue(0);
//     printf("The Elements of linked list after enqueuing are\n");
//     linkedListTraversal(f);

//     dequeue();
//     dequeue();
//     printf("The Elements of linked list after dequeueing are\n");
//     linkedListTraversal(f);
//     return 0;
// }
