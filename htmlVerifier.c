#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

// Defining a stack type and all its basic methods.
typedef struct stack_entry
{
    int tagValue;
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

// char *copyString(char *str)
// {
//   char *tmp = malloc(strlen(str) + 1);
//   if (tmp)
//   {
//     strcpy(tmp, str);
//     return tmp;      
//   }
//   return NULL;
// }

void push(struct stack *myStack, int newTag)
{
    struct stack_entry *newEntry = malloc(sizeof(struct stack_entry));
    if (newEntry)
    {
        newEntry->tagValue = newTag;
        newEntry->next = myStack->head;
        myStack->head = newEntry;
    }
    else {
        printf("Entry could not be pushed into the stack");
    }
}

int peek(struct stack *myStack)
{
    if(myStack && myStack->head)
    {
        return myStack->head->tagValue;
    }
    else
    {
        return -1;
    }
}

void pop(struct stack *myStack)
{
    if(myStack->head != NULL)
    {
        struct stack_entry *temp;
        temp = myStack->head;
        myStack->head = myStack->head->next;
        printf("\n\n%d deleted", temp->tagValue);
        free(temp);
    }
}

char *appendCharacter(char *string, char newChar){
    size_t len = strlen(string);
    char *tmp = malloc(sizeof(string) + sizeof(char) * 2);
    strcpy(tmp, string);

    tmp[len] = newChar;
    tmp[len+1] = '\0';

    return tmp;
}

char *readFile(){
    FILE *fPointer;
    fPointer = fopen("file.html", "r");
    char currentChar;
    

    while(!feof(fPointer)){
        currentChar = fgetc(fPointer);
        if(currentChar == '<'){
            char *tag = "<";
            currentChar = fgetc(fPointer);
            while(currentChar != '>')
            {
                appendCharacter(tag, currentChar);
                currentChar = fgetc(fPointer);
            }
            printf("%s\n", tag);
        }
    }
    fclose(fPointer);
}

// code for reading the file character by character
int main () {
    // char *myString = "";
    // char *appendedString = appendCharacter(myString, 'H');
    // printf("%s\n", appendedString);
    readFile();
}