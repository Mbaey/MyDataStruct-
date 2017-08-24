#include <stdio.h>
#include <stdlib.h>
#define Max 5   //????????for(i=0; i<l; i++)   {       free(s->base);        s->base++;    }
#define N 10
typedef struct stack
{
    int data;
    int *top, *base;
}Sta;

void InitQ(Sta *s)
{
    s->base = (int *)malloc(Max * sizeof(Sta));
    if(!s->base) exit(0);
    s->top = s->base;
    s->data = Max;     //数据放哪？
}

void Push(Sta *s, int e)
{
    if(s->top - s->base >= s->data)
    {
        s->base = (int *)realloc(s->base, N * sizeof(Sta));
        if(!s->base)
            exit(0);
        s->top = s->base + s->data;
        s->data += N;
    }

    *(s->top) = e;
    s->top++;
}

int Pop(Sta *s)
{
    int e;
    if(s->base == s->top) return 0;
    e = *--(s->top);  //读出top值， top--；
    return e;
}

void ClearSta(Sta *s)   //让所有数据无效
{
    s->top = s->base;
}

//void DestroySta(Sta *s)   不知道哪里错了？
//{
//    int *t;
//    s->top = s->base + s->data;
//    while(s->base != s->top)
//    {
//        t = s->top--;
//        free(t);
//    }
//    s->base = s->top = NULL;
//    s->data = 0;
//}

void DestroySta(Sta *s)
{
    int i, l;
    l = s->data;
    for(i=0; i<l; i++)
    {
        free(s->base);
        s->base++;
    }
    s->base = s->top = NULL;
    s->data = 0;
}
int main()
{
    int i, t;
    Sta stack, *s = &stack;
    InitQ(s);
    for(i=0; i<5; i++)
    {
        scanf("%d", &t);
        Push(s, t);
    }
    for(i=4; i>=0; i--)
    {
        printf("%d ", Pop(s));
    }

    DestroySta(s);

    printf("%d  Hello world!\n", 9%7);
    return 0;
}

