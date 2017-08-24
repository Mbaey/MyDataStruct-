#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2

typedef char ElemType;
typedef int Status;

typedef struct stack
{
    ElemType *Top;
    ElemType *Base;
    int stackSize;
}intStack;

void InitStack(Stack *s)
{
    s->Base = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
    if(!s->Base)     {printf("No memory!");   exit(0);}

     s->Top = s->Base;
     s->stackSize = 0;
     return s;
}

void Push(Stack *s, int data)
{
    if(s->stackSize >= STACK_INIT_SIZE)
        {
            s->Base = (ElemType *)realloc(s->Base, (sizeof(s->Base) + sizeof(ElemType)*5));
            if(!s->Base)     {printf("No memory!");   exit(0);}
        }
    *s->Top = data;
    s->Top++;
    s->stackSize++;
}

ElemType Pop(Stack *s)
{
    ElemType d;
    if(!s->stackSize)
    {
        printf("No data!\n");
        return -1;
    }

    s->Top--;
    d = *s->Top;
    s->stackSize--;
    return d;
}

void DestroyStack(Stack *s)
{
    free(s->Base);
    s->Base = s->Top = NULL;
    s->stackSize = 0;
}

int StackLen(Stack *s)
{
    return (s->Top - s->Base);
}

void DisplayData(Stack *s)
{
    ElemType *f = s->Base;
    int i = 0;

    for(; i < s->stackSize; i++, f++)
    {
        printf("  %d", *f);
    }
    putchar('\n');

//    ElemType *elem = s->base;
//    if(s->base == s->top){
//    printf("This is an empty stack!\n");
//    }
//    for(elem ; elem != s->top ; elem++){
//    printf("element is %d", *elem);
//    printf("\n");
}


int main()
{
    
    return 0;
}

