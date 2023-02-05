#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_entry
{
    char *string;
    struct stack_entry *next;
} stack_entry;

typedef struct stack
{
    struct stack_entry *head;
} stack;

struct stack *newStack(void)
{
    struct stack *stack = malloc(sizeof *stack);
    if (stack)
    {
        stack->head = NULL;
    }
    return stack;
}

char *copyString(char *str)
{
  char *tmp = malloc(strlen(str) + 1);
  if (tmp)
  {
    strcpy(tmp, str);
    return tmp;      
  }
  return NULL;
}

void push(struct stack *myStack, char *string)
{
    struct stack_entry *newEntry = malloc(sizeof *newEntry);
    if (newEntry)
    {
        newEntry->string = copyString(string);
        newEntry->next = myStack->head;
        myStack->head = newEntry;
    }
    else {
        printf("Not enough memory to store new entry to the stack.");
    }
}

char *peek(struct stack *myStack)
{
    if(myStack && myStack->head)
    {
        return myStack->head->string;
    }
    else
    {
        return NULL;
    }
}

void pop(struct stack *myStack)
{
    if(myStack->head != NULL)
    {
        struct stack_entry *tmp = myStack->head;
        myStack->head = myStack->head->next;
        free(tmp);
    }
}

int main()
{
    // FILE *fPointer;
    // fPointer = fopen("file.html", "r");

    // char singleLine[MAXLINE];

    // while (!feof(fPointer))
    // {
    //     fgets(singleLine, 150, fPointer);
    //     printf(singleLine);
    // }

    // fclose(fPointer);

    // return 0;

    struct stack *myStack = newStack();

    char *string1 = "hello1";
    char *string2 = "hello2";
    char *string3 = "hello3";

    push(myStack, string1);
    push(myStack, string2);
    push(myStack, string3);

    
    while(myStack->head != NULL){
        printf("%s\n", myStack->head->string);
        pop(myStack);
    }

    
    // int *x;
    // int y = 10;
    // x = &y;

    // printf("%p\n", x);
    // printf("%d\n", *x);
}