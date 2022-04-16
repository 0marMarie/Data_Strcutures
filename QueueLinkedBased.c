// Author     :  Omar Hamed Marie
// Description:  queue-linked-based
// Date       :  27  DEC 2021
// Version    :  V1.1

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a Queue structure
typedef struct queuenode
{
    int Data;
    struct queuenode* Next;
} QueueNode;

// Define a Queue structure
typedef struct queue
{
    int size;
    QueueNode* Front;
    QueueNode* Rear;
} Queue;

// Prototypes of Functions
void Queue_voidInit   (Queue *pq);
void Queue_voidEnQueue(int Copy_intValue, Queue *pq);
int  Queue_intIsFull  (Queue *pq);
void Queue_voidDeQueue(Queue *pq, int *pd);
int  Queue_intIsEmpty (Queue *pq);
int  Queue_voidSize   (Queue *pq);
void Queue_voidPrint  (Queue *pq);
void Queue_voidClear  (Queue *pq);

int main()
{
    int size, poped;
    Queue q1;

    Queue_voidInit(&q1);

    Queue_voidEnQueue(5, &q1);
    Queue_voidEnQueue(23, &q1);
    Queue_voidEnQueue(2, &q1);
    Queue_voidEnQueue(78, &q1);
    
    Queue_voidPrint(&q1);
    size = Queue_voidSize(&q1);
    printf("\nSize is    : %d\n", size);

    Queue_voidDeQueue(&q1, &poped);
    printf("Poped Value: %d\n", poped);

    size = Queue_voidSize(&q1);
    printf("Size is    : %d\n", size);

    Queue_voidClear(&q1);
    Queue_voidPrint(&q1);
    return 0;
}

void Queue_voidInit(Queue *pq)
{
    pq->Front = NULL;
    pq->Rear  = NULL;
    pq->size  = 0;
}

void Queue_voidEnQueue(int Copy_intValue, Queue *pq)
{
    // Allocate size of QueueNode in Memory!
    QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
    // Assign my value in the data field
    pn->Data = Copy_intValue;
    // Make Next point to Null
    pn->Next = NULL;

    // Initial EnQueue -> Front point to "pn"
    if (pq->Front == NULL)
        pq->Front = pn;
    // Make Rear Next to point to new EnQueued element "pn"
    else
        pq->Rear->Next = pn;
    // Update Rear to point to new EnQueued element "pn"
    pq->Rear = pn;

    // Increament size
    pq->size++;
}

int Queue_intIsFull(Queue *pq)
{
    return 0;
}

int Queue_intIsEmpty(Queue *pq)
{
    return (pq->Front == NULL);
}

int Queue_voidSize(Queue *pq)
{
    return (pq->size);
}

void Queue_voidDeQueue(Queue *pq, int *pd)
{
    if(Queue_intIsEmpty(pq))
    {
        printf("Empty Queue. you can't dequeue. \n");
    }
    else
    {
        // Create a new pointer to hold the current front
        QueueNode *pn = pq->Front;
        // Return data field of the current front
        *pd = pn->Data;
        // Update the front to ponit to the next element
        pq->Front = pq->Front->Next;
        // Deallocate the old Front Node
        free(pn);

        if (pq->Front == NULL)
        {
            pq->Rear = NULL;
        }
        pq->size--;
    }
    
}

void Queue_voidPrint(Queue *pq)
{
    QueueNode *pn;
    if (pq->Front == NULL)
    {
        printf("\nQueue is Empty!\n\n");
    }
    else
    {
        pn = pq->Front;
        while (pn != NULL)
        {
            printf("%d \n", pn->Data);
            pn = pn->Next;
        }
    }
}

void Queue_voidClear(Queue *pq)
{
    QueueNode *pn = pq->Front;

    while (pn != NULL)
    {
        pq->Front = pq->Front->Next;
        free(pn);
        pn = pq->Front;
    }
    pq->size = 0;
}
