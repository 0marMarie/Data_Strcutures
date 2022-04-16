// Author     :  Omar Hamed Marie
// Description:  queue-array-based
// Date       :  27  DEC 2021
// Version    :  V1.0

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Define a stack structure
typedef struct queue
{
    int size;
    int Front;
    int Rear;
    int Arr[MAX_SIZE];
} Queue;

// Prototypes of Functions
void Queue_voidInit(Queue *pq);
void Queue_voidEnQueue(int Copy_intValue, Queue *pq);
int  Queue_intIsFull(Queue *pq);
void Queue_voidDeQueue(Queue *pq, int *pd);
int  Queue_intIsEmpty(Queue *pq);
int  Queue_voidSize(Queue *pq);
void Queue_voidPrint(Queue *pq);

// App Entry Point
int main()
{
    int FrontNode, size;
    Queue q1;

    Queue_voidInit(&q1);

    Queue_voidEnQueue(5, &q1);
    Queue_voidEnQueue(2, &q1);
    Queue_voidEnQueue(25, &q1);

    Queue_voidPrint(&q1);
    size = Queue_voidSize(&q1);
    printf("Size is : %d\n", size);

    printf("\n=================\n\n");

    Queue_voidDeQueue(&q1, &FrontNode);
    Queue_voidDeQueue(&q1, &FrontNode);

    printf("The Front Node is: %d\n", FrontNode);
    size = Queue_voidSize(&q1);
    printf("Size is : %d\n\n", size);

    Queue_voidEnQueue(15, &q1);
    Queue_voidEnQueue(5, &q1);
    Queue_voidEnQueue(76, &q1);

    Queue_voidPrint(&q1);

    return 0;
}

void Queue_voidInit(Queue *pq)
{
    pq->Front = -1;
    pq->Rear = -1;
    pq->size = 0;
}

void Queue_voidEnQueue(int Copy_intValue, Queue *pq)
{
    if (Queue_intIsFull(pq))
    {
        printf("\nQueue is full\n");
    }
    else
    {
        // Initial Enqueue
        if (pq->Front == -1)
            pq->Front = 0;

        // Normal EnQueue
        pq->Rear = (pq->Rear+1) % MAX_SIZE;
        pq->Arr[pq->Rear] = Copy_intValue;
        pq->size++;
    }
}

int Queue_intIsFull(Queue *pq)
{
    return ( (pq->Front == pq->Rear+1)|| ((pq->Rear == MAX_SIZE - 1)&&(pq->Front ==0)) );
}

void Queue_voidDeQueue(Queue *pq, int *pd)
{
    int i;
    if (Queue_intIsEmpty(pq))
    {
        printf("The queue is empty. You can't deQueue!");
    }
    else
    {
        // Return the value of the dequeued front pointer data
        *pd = pq->Arr[pq->Front];
        pq->size--;

        // Reset the Queue
        if (pq->Front > pq->Rear)
        {
            pq->Rear = -1;
            pq->Front = -1;
            pq->size = 0;
        }
        else
            pq->Front = (pq->Front+1) % MAX_SIZE;
    }
}

int Queue_intIsEmpty(Queue *pq)
{
    return (pq->Front == -1);
}

int Queue_voidSize(Queue *pq)
{
    return (pq->size);
}

void Queue_voidPrint(Queue *pq)
{
    int i;
    if (Queue_intIsEmpty(pq))
    {
        printf("You can't print \n");
    }
    else
    {
        for(i = pq->Front; i != pq->Rear; i = (i+1)%MAX_SIZE)
            printf("%d\n", pq->Arr[i]);
        
        printf("%d \n", pq->Arr[i]);
    }
}
