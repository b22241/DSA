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

void enqueueforward(struct Queue *q, int val)
{
    if (q->b == q->size - 1 &&q->f== q->size - 1)
    {
        printf("Arrary is Full, can't enqueue %d to the Queue\n",val);
    }
   else {
        if (q->f == -1) { // When the first element is enqueued
            q->f = 0;
        }
        q->f=q->f-1;
        q->arr[q->f]=val;
    }
}


void enqueuebackward(struct Queue *q, int val)
{
    if (q->b == q->size - 1 &&q->f== q->size - 1)
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

int dequeueforward(struct Queue *q)
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

int dequeuebackward(struct Queue *q)
{
    int val=-1;
    if (q->f == -1 && q->b == -1)
    {
        printf("Array is empty, can't dequeue element from it");
    }
    else
    {
        int val = q->arr[q->f];
        q->b=q->b-1;
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

    enqueuebackward(q, 5);
    enqueuebackward(q, 10);
    enqueuebackward(q, 14);
    enqueuebackward(q, 4);
    enqueueforward(q, 14);
    printf("Array after enqueue\n");
    printQueue(q);
    dequeuebackward(q);
    dequeuebackward(q);
    dequeueforward(q);
    printf("Array after dequeue\n");
    printQueue(q);
    return 0;
}

  
  
