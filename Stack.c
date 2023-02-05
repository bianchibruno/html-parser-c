#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define HTML_TAG 1
#define HEAD_TAG 2
#define BODY_TAG 3
#define TITLE_TAG 4
#define H1_TAG 5
#define H2_TAG 6
#define H3_TAG 7
#define P_TAG 8
#define UL_TAG 9
#define LI_TAG 10
#define A_TAG 11
#define DIV_TAG 12

struct Stack 
{
    int top;
    int numberOfElements;
    int sizeOfArray;
    int* array;    
};

struct Stack* create_stack(void);
bool is_full(struct Stack*);
bool is_empty(struct Stack*);
void push(struct Stack*, int);
void pop(struct Stack*);
int peek(struct Stack*);
bool contains(struct Stack*, int);

struct Stack* create_stack()
{
    struct Stack* stack = malloc(sizeof(struct Stack));;
    stack -> top = 0;
    stack -> numberOfElements = 0;
    stack -> sizeOfArray = 20*sizeof(int);
    stack -> array = calloc(20, sizeof(int));
    return stack;
}

bool is_full(struct Stack* stack)
{
    return !(stack->numberOfElements < stack->sizeOfArray);
}

bool is_empty(struct Stack* stack)
{
    return (stack->numberOfElements == 0);
}

void push(struct Stack* stack, int number)
{
    if(is_full(stack))
    {
        stack->array = realloc(stack->array, (stack->sizeOfArray)*2);
    }
    (stack->array)[stack->numberOfElements] = number;
    stack -> numberOfElements += 1;
}

void pop(struct Stack* stack) 
{
    (stack->array)[stack->numberOfElements -1] = 0;
    stack->numberOfElements -= 1;
}

int peek(struct Stack* stack) 
{
    return (stack->array)[stack->numberOfElements -1];
}

bool contains(struct Stack* stack, int number) 
{
    for (int i = 0; i < stack->numberOfElements; i++)
    {
        if ((stack->array)[i] == number)
        {
            return true;
        }
    }
    return false;
}