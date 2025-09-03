#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int f;
    int b;
    int *arr;
};

void printQueue(struct Queue *q) {
    if (q->f==-1 &&q->b==-1) {
        printf("Queue is Empty\n");
    } else {
        for (int i = q->f; i <= q->b; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

void enqueue(struct Queue *q, int val)
{
    if (q->b == q->size - 1)
    {
        printf("Arrary is Full, can't enqueue %d to the Queue\n",val);
    }
   else {
        if (q->f == -1) { // When the first element is enqueued
            q->f = 0;
        }
        q->b = q->b + 1;
        q->arr[q->b] = val;
    }
}

int dequeue(struct Queue *q)
{
    int val=-1;
    if (q->f == -1 && q->b == -1)
    {
        printf("Array is empty, can't dequeue element from it");
    }
    else
    {
        int val = q->arr[q->f];
        q->f=q->f+1;
        // return val;
    }
}


int main()
{
    
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = 10;
    q->f = -1;
    q->b = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 50);
    printf("Array after enqueue\n");
    printQueue(q);
    dequeue(q);
    dequeue(q);
    printf("Array after dequeue\n");
    printQueue(q);
    return 0;
}

  
  
