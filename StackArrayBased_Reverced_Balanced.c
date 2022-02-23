// Author     :  Omar Hamed Marie
// Description:  stack-array-based-implements-reverse-balanced
// Date       :  25  DEC 2021
// Version    :  V1.2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define a stack structure
typedef struct stack
{
  int Top;
  int Arr[MAX_SIZE];
  int size;
} Stack;


// Prototypes of Functions
void Stack_voidInit         (Stack* ps);
void Stack_voidPush         (int Copy_intValue, Stack *ps);
int  Stack_intPop           (Stack* ps);
int  Stack_intReturnTopValue(Stack *ps);
int  Stack_intIsFull        (Stack *ps);
int  Stack_intIsEmpty       (Stack *ps);
void Stack_voidPrintElements(Stack *ps);
int  Stack_voidSize         (Stack *ps);
void Stack_voidReverse      (char str[]);
int  Stack_intParenthesis   (char str[]);
int  Stack_intMatch         (char x, char y);

// App Entry Point
int main()
{
  int TopValue, StackSize;
  // Reverse the str
  char str[] = "Omar Marie";
  // Check balanced str2
  char str2[] = "{}()8()*--$$9()()";
  Stack s1;
  
  // Stack One -> Implement Print Function
  // Initialize top value
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

  printf("\n=====================\n\n");

  // Stack Two -> Reverse a word Task
  printf("String before reversing: %s\n", str);
  Stack_voidReverse(str);
  printf("String after reversing : %s\n", str);

  printf("\n=====================\n\n");

  // Stack Trhee -> Balanced Check Task
  if (Stack_intParenthesis(str2))
    printf("Balanced\n\n");
  else
    printf("Not Balanced\n\n");
  return 0;
}

void Stack_voidInit(Stack *ps)
{
  ps->Top = -1;
  ps->size = 0;
}

void Stack_voidPush(int Copy_intValue, Stack *ps)
{
  // Check if stack is full
  if(Stack_intIsFull(ps))
    printf("Stack is full, You can't push!\n");
  else
  {
    // 1- increament top
    ps->Top++;
    // 2- Assign the value to Arr[Top]
    ps->Arr[ps->Top] = Copy_intValue;
    ps->size++;
  }
}

int Stack_intPop(Stack *ps)
{
  if(!Stack_intIsEmpty(ps))
  {
    // Assign to temp variable
    int TopValue;
    // 1- Return top value
    TopValue = ps->Arr[ps->Top];
    // 2- Decreament top indicator
    ps->Top--;
    // Decreament size
    ps->size--;
    // return TopValue
    return TopValue;
  }
  else
  {
    printf("Stack is Empty, You can't Pop!\n");
    return 0;
  }
}

int Stack_intReturnTopValue(Stack *ps)
{
  if (ps->Top != -1)
    // Return top value
    return ps->Arr[ps->Top];
  else
  {
    printf("Stack is Empty, You can't return top value!\n");
    return 0;
  }
}

int Stack_intIsFull(Stack *ps)
{
  return (ps->Top == MAX_SIZE -1);
}

int Stack_intIsEmpty(Stack *ps)
{
  return (ps->Top == -1);
}

void Stack_voidPrintElements(Stack *ps)
{
  if (ps->Top == -1)
    printf("\nStack Underflow!!");
  else
  {
    printf("\nStack Elements: \n");
    for (int i = ps->Top; i >= 0; --i)
      printf("%d\n", ps->Arr[i]);
  }
}

int Stack_voidSize(Stack *ps)
{
  return ps->size;
}


// Implementation of reverse word program
void Stack_voidReverse(char str[])
{
  int n = strlen(str);
  Stack s2;
  Stack_voidInit(&s2);

  // Push
  for (int i = 0; i < n; i++)
    Stack_voidPush(str[i] ,&s2);
  
  //Pop
  for (int i = 0; i < n; i++)
    str[i] = Stack_intPop(&s2);
}

// Implementation of Parenthesis program
int Stack_intParenthesis(char str[])
{
  // Create and initialize the stack
  Stack s3;
  Stack_voidInit(&s3);
  char removedChar;

  for (int i = 0; i < strlen(str); i++)
  {

    if (str[i] == '(' || str[i] == '{' || str[i] == '[')
      Stack_voidPush(str[i], &s3);

    else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
    {
      if (Stack_intIsEmpty(&s3))
        return 0;

      removedChar = Stack_intPop(&s3);

      if (!Stack_intMatch(removedChar, str[i]))
        return 0;

    }
  }

  if (Stack_intIsEmpty(&s3))
    return 1;

  else
    return 0;

}

int Stack_intMatch(char a, char b)
{
  if (a == '{' && b == '}')
    return 1;

  if (a == '(' && b == ')')
    return 1;

  if (a == '[' && b == ']')
    return 1;

  return 0;
}
