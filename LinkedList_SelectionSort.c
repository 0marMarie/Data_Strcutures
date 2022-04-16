// Author     :  Omar Hamed Marie
// Description:  linked-list-selection-sort
// Date       :  29  DEC 2021
// Version    :  V1.1

#include <stdio.h>
#include <stdlib.h>


typedef struct listnode
{
    int Data;
    struct listnode* Next;
} ListNode;


typedef struct list
{
    ListNode *head;
    int size;
}List;


// Prototypes
void List_voidInit         (List* pl);
void List_voidInsertList   (int Pos, List* pl, int Copy_intValue);
void List_voidReplaceList  (int Pos, List* pl, int Copy_intValue);
void List_voidRemoveList   (int Pos, List* pl, int* pd);
void List_voidRetriveList  (int Pos, List* pl, int* pd);
int  List_intIsEmpty       (List* pl);
int  List_intIsFull        (List* pl);
int  List_intSize          (List* pl);
void List_voidPrintList    (List* pl);
void List_voidDestroyList  (List* pl);
void List_voidSelectionSort(List *pl);

// App Entry Point
int main()
{
    int size, RetrivedValue;
    List L;

    // Initialize List
    List_voidInit(&L);

    // Insert Elements into List
    List_voidInsertList(0, &L, 23);
    List_voidInsertList(1, &L, 3);
    List_voidInsertList(2, &L, 7);
    List_voidInsertList(3, &L, 13);
    List_voidInsertList(4, &L, 8);
    List_voidInsertList(5, &L, 67);

    // Print the size
    size= List_intSize(&L);
    printf("\nSize is: %d\n", size);

    // Print List
    printf("Elements are: \n");
    List_voidPrintList(&L);
    
    printf("\n====================\n\n");

    // Get a value at specific Pos
    List_voidRetriveList(2, &L, &RetrivedValue);
    printf("The Retrived Value is: %d\n", RetrivedValue);

    // Remove a value at Pos and Retrive It
    List_voidRemoveList(4,&L, &RetrivedValue);
    printf("The Recent Removed Value is: %d\n", RetrivedValue);
    
    // Print the size
    size= List_intSize(&L);
    printf("Size is: %d\n", size);
    
    printf("\n====================\n\n");

    // Sort the List
    List_voidSelectionSort(&L);
    printf("Sorted elements are: \n");
    List_voidPrintList(&L);

    printf("\n");
}

void List_voidInit(List* pl)
{
    pl->head = NULL;
    pl->size = 0;
}

int  List_intIsEmpty(List* pl)
{
    return (pl->head == NULL);
}

int  List_intIsFull(List* pl)
{
    return 0;
}

int  List_intSize(List* pl)
{
    return (pl->size);
}

void List_voidInsertList(int Pos, List* pl, int Copy_intValue)
{
    //Create a List pointer
    ListNode* q;
    int i;

    // Initialize a new node
    ListNode* pn = (ListNode*)malloc(sizeof(ListNode));
    pn->Data =   Copy_intValue;
    pn->Next =   NULL;

    // First Loop only
    if(Pos == 0)
    {
        pn->Next = pl->head;
        pl->head = pn;
    }
    else
    {
        for(q = pl->head, i=0; i< Pos-1; i++)
            q = q->Next;
        pn ->Next= q->Next;
        q->Next= pn;
    }

    pl->size++;
}

void List_voidReplaceList(int Pos, List* pl, int Copy_intValue)
{
    // Create a List Pointer
    int i;
    ListNode* q;

    // Replace in place
    for(q= pl->head, i=0; i<Pos; i++)
        q = q->Next;

    q->Data= Copy_intValue;

}

void List_voidRemoveList(int Pos, List* pl, int* pd)
{
    // Create a List Pointer
    int i;
    ListNode *q;
    ListNode *temp;

    // First Loop only
    if(Pos==0)
    {
        *pd = pl->head->Data;
        temp = pl->head->Next;
        free(pl->head);
        pl->head= temp;
    }
    else
    {
        for(q= pl->head, i=0; i<Pos-1; i++)
            q = q->Next;
        
        *pd = q->Next->Data;
        temp= q->Next->Next;
        free(q->Next);
        q->Next = temp;

    }
    pl->size--;
}

void List_voidRetriveList(int Pos, List* pl, int* pd)
{
    int i;
    ListNode* q;

    for(q= pl->head, i=0; i< Pos; i++)
        q = q->Next;
    *pd= q->Data;
}

void List_voidPrintList(List* pl)
{
    ListNode* q= pl->head;

    while(q != NULL)
    {
        printf("%d\n", q->Data);
        q= q->Next;
    }
}

void List_voidDestroyList(List* pl)
{
    ListNode* temp;

    while(pl->head != NULL)
    {
        temp = pl->head->Next;
        free(pl->head);
        pl->head= temp;
    }

    pl->size = 0;
}

void List_voidSelectionSort(List* pl)
{
    ListNode *q = pl->head;

    // Loop through the List
    while (q)
    {
        ListNode *min = q;
        ListNode *r   = q->Next;

        // Set the minimumu
        while (r)
        {
            if (min->Data > r->Data)
                min = r;
            r = r->Next;
        }

        // Swap the list elemets
        int s = q->Data;
        q->Data = min->Data;
        min->Data = s;
        q = q->Next;
    }
}