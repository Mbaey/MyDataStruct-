#include <stdio.h>
#include <stdlib.h>
#define Maxlen 10
typedef struct lianbiao
{
    int data;
    int *next;
}list;

list *CreadList(int n)
{
    list *p, *last, *head = NULL; //p:创建一个    last:最后一个    head:第一个
    int i=0;
    do{
        p = (list *)malloc(sizeof(list));
        if(!p) printf("memory error!\n");
        printf("No.%d data!\n", i);
        scanf("%d", &p->data);
        p->next = NULL;

        if(!head) head = p;
        else
        {
            last->next = p;
            printf("%d,%d %p %p\n", p->data, last->data, p->next, last->next);
        }
        last = p;
        i++;
    }while(i <= n);
    return head;
}

void DestroyList(list *head)
{
    list *p, *q;                            //q:下一个
    p = head;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    head = NULL;
}

void InsertLast(list *head, list *q, int e)
{
    list *p;
    p = (list *)malloc(sizeof(list));
    p->data = e;
    if(!head)
    {
        head = p;
        head->next = NULL;
    }
    else
    {
        p->next = q->next;
        q->next = p;
    }
}

void DelLink(list *head, list *q)           //删除q！
{
    list *r;
    if(q == head)
        head->next = q->next;
    else
    {
        for(r=head; r->next!=q; r=r->next);  //找到q！！！
        if(r->next != NULL)
            r->next = q->next;
        else
            exit(0);
    }

    free(q);
}
int main()
{
    list *head, *p;
    int i;
    head = CreadList(10);
    p = head;
    for(i=0; i<4; i++)      //循环至链表内的第四个数据；得到第4个数据的指针；！
    {
        p=p->next;
    }
    InsertLast(head, p, 88);
    DelLink(head, p);
    while(head)
    {
        printf("%d ", (*head).data);
        head = head->next;
    }
    DestroyList(head);
    while(head)
    {
        printf("%d ", (*head).data);
        head = head->next;
    }
    return 0;
}
