// Author     :  Omar Hamed Marie
// Description:  stack-linked-based
// Date       :  26  DEC 2021
// Version    :  V1.0

#include <stdio.h>
#include <stdlib.h>

// Structure for stack nodes
typedef struct stacknode
{
    int Data;
    struct stacknode* Next;
} StackNode;

typedef struct stack
{
    StackNode *Top;
    int size;
} Stack;

// Prototypes
void Stack_voidInit         (Stack *ps);
void Stack_voidPush         (int Copy_intValue, Stack *ps);
int  Stack_intPop           (Stack *ps);
int  Stack_intReturnTopValue(Stack *ps);
int  Stack_intIsFull        (Stack *ps);
int  Stack_intIsEmpty       (Stack *ps);
void Stack_voidPrintElements(Stack *ps);
int  Stack_voidSize         (Stack *ps);
void Stack_clearStack       (Stack *ps);

int main()
{
    int TopValue, StackSize;
    char str[] = "Omar Marie";
    Stack s1;

    // Initialize top value and size
    Stack_voidInit(&s1);
    // Push 5 Elements
    Stack_voidPush(5, &s1);
    Stack_voidPush(7, &s1);
    Stack_voidPush(2, &s1);
    Stack_voidPush(13, &s1);
    Stack_voidPush(22, &s1);

    // Print the elements inside the stack
    Stack_voidPrintElements(&s1);

    // Print the Top Value and Size of Stack
    StackSize = Stack_voidSize(&s1);
    TopValue = Stack_intPop(&s1);
    printf("Stack top value: %d\n", TopValue);
    printf("Stack Size: %d\n", StackSize);

    printf("\n=======================\n");

    // Clear Stack and print elements and size
    Stack_clearStack(&s1);
    Stack_voidPrintElements(&s1);
    StackSize = Stack_voidSize(&s1);
    printf("\nStack Size: %d\n\n", StackSize);

    return 0;
}

void Stack_voidInit(Stack *ps)
{
    ps->Top = NULL;
    ps->size = 0;
}

void Stack_voidPush(int Copy_intValue, Stack *ps)
{
    // 1- Create a node
    // 1.1- Allocate size of stack node in memory
    StackNode* pn = (StackNode*) malloc(sizeof(StackNode));
    // 1.2- Assign my value in the data field
    pn->Data = Copy_intValue;
    // 1.3- 
    pn->Next = ps->Top;
    // 2- Update Top pointer to point to Top node
    ps->Top = pn;
    // Increament size
    ps->size++;
}

int Stack_intIsFull(Stack *ps)
{
    return 0;
}

// Change to use pointers to return
int Stack_intPop(Stack *ps)
{
    if (!Stack_intIsEmpty(ps))
    {
        // return the data filed of the top node
        int TopValue;
        TopValue = ps->Top->Data;
        // Make a Temporary pointer
        StackNode *pn = ps->Top;
        // Upadate Top pointer
        ps->Top = ps->Top->Next;
        // Deallocate the old pointer
        free(pn);
        // Decreament size
        ps->size--;
        // return topvalue
        return TopValue;
    }
    else
    {
        printf("Stack Underflow\n");
        return 0;
    }
}

int Stack_intIsEmpty(Stack *ps)
{
    return (ps->Top == NULL);
}

int Stack_intReturnTopValue(Stack *ps)
{
    int TopValue;
    TopValue = ps->Top->Data;
    return TopValue;
}

int Stack_voidSize(Stack *ps)
{
    return (ps->size);
}

void Stack_voidPrintElements(Stack *ps)
{
    StackNode *pn;

    if (ps->Top == NULL)
    {
        printf("\nStack is Empty!");
    }
    else
    {
        pn = ps->Top;
        while (pn != NULL)
        {
            printf("%d \n", pn->Data);
            pn = pn->Next;
        }
    }
}

void Stack_clearStack(Stack *ps)
{
    StackNode *pn = ps->Top;

    while (pn != NULL)
    {
        ps->Top = ps->Top->Next;
        free(pn);
        pn = ps->Top;
    }
    ps->size = 0;
}
