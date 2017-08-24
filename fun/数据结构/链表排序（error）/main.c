#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxlen 10

typedef struct link
{
    int data;
    struct link *next;
}L;

void Cread(L *h)
{
    L *p = NULL, *last = h;
    char c;
    int a;
    printf("Do you want to append?(Y/N)\n");
    scanf("%c", &c);
    while(c == 'Y')
    {
        p = (L*)malloc(sizeof(L));

        if(!p) exit(0);
        p->next = NULL;
        scanf("%d", &a);
        p->data = a;
        if(!h)
            h = p;
        else
            last->next = p;
        last = p;
        printf("Do you want to append?(Y/N)\n");
        scanf(" %c", &c);
    }
}
void Destroy(L *h)
{
    L *p = h, *q = NULL;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    h = NULL;
}

void Display(L *h)
{
    h = h->next;
    while(h)
    {
        printf("%d ", h->data);
        h = h->next;
    }
}

void Sort(L *q)
{
    L *p = q;
    int t, i, j, k = 0;
    for(; p != NULL; p=p->next, k++);
    p = q;
    for(i=0; i<k-1; i++)
    {
        for(j=0; j<k-i-1; j++)
        {
            if((p->data) > (p->next->data))
            {
                t = p->data;
                p->data = p->next->data;
                p->next->data = t;
            }
            Display(q);
            p = p->next;
        }
        p = q;
    }
}

int main()
{
    L head, *h = &head;
    Cread(h);
    Display(h);
    Sort(h);
    Display(h);
    Destroy(h);
    return 0;
}
