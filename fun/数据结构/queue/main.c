#include <stdio.h>
#include <stdlib.h>
#define Maxlen 10


typedef struct Qnode
{
    int data;
    struct Qnode *next;
}Q;
typedef struct
{
    Q *fronf;
    Q *rear;
}LinkQ;

void InitQue(LinkQ *q)
{
    q->fronf = q->rear = (Q*)malloc(sizeof(Q));
    if(!q->fronf) exit(0);
    q->fronf->next = NULL;
}

void EnQue(LinkQ *q, int e)
{
    Q *p;
    p = (Q*)malloc(sizeof(Q));
    if(!q->fronf) exit(0);
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

void DeQue(LinkQ *q, int *e)
{
    Q *p = NULL;
    if(q->fronf == q->rear) return;
    p = q->fronf->next;
    *e = p->data;
    q->fronf->next = p->next;
    if(q->rear == p)
        q->rear = q->fronf;
    free(p);
}

void DestroyQue(LinkQ *q)
{
    while(q->fronf)
    {
        q->rear = q->rear->next;
        free(q->fronf);
        q->fronf = q->rear;
    }
}

int main()
{

    return 0;
}
