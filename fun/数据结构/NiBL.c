#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2

typedef double ElemType;
typedef int Status;

typedef struct stack
{
    ElemType *Top;
    ElemType *Base;
    int stackSize;
}Stack;

void InitStack(Stack *s)
{
    s->Base = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
    if(!s->Base)     {printf("No memory!");   exit(0);}

     s->Top = s->Base;
     s->stackSize = 0;
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
        printf("  %f", *f);
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
    Stack s;
    InitStack(&s);
    char a[10], ch;
    double d1, d2;
    int i;
    while((ch = getchar()) != '#')
    {
        i = 0;
        while(isdigit(ch) || ch == '.')
        {
            a[i++] = ch;
            a[i] = '\0';
            ch = getchar();
            if(ch == ' ')
            {
                Push(&s, atof(a));
                DisplayData(&s);
                i = 0;
                break;
            }

            if(ch == '#')
                break;
        }



        switch( ch )
        {
            case '+':
                d1 = Pop(&s);
                d2 = Pop(&s);
                Push(&s, d1 + d2);
                DisplayData(&s);
                break;
            case '-':
                d1 = Pop(&s);
                d2 = Pop(&s);
                Push(&s, d2 - d1);
                DisplayData(&s);
                break;
            case '*':
                d1 = Pop(&s);
                d2 = Pop(&s);
                Push(&s, d1 * d2);
                DisplayData(&s);
                break;
            case '/':
                d1 = Pop(&s);
                d2 = Pop(&s);
                if(d2 == 0)
                    return -1;
                Push(&s, d2 / d1);
                break;
        }

    }
    printf("The end:%f", Pop(&s));

    return 0;
}

