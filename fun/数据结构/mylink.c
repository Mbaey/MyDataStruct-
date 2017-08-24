#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int data;
    struct link *next;
}Link;

Link *CreadLink(int m)
{
    Link *h = NULL, *pre, *n;   /* *pre是最后一个元素，也是下一个创建的元素的前一个。*/   
    int i;								 /*但我这个没有头！！插入不到第一个位置上！*/
    h = (Link *)calloc(1, sizeof(Link));
    h->next = NULL;
    pre = h;
    if(!h)     {printf("No memory!");   exit(0);}

    for(i = 0; i < m; i++)
    {
        n = (Link *)calloc(1, sizeof(Link));
        if(!n)     {printf("No memory!");   exit(0);}
        printf("No.%d data is:\n", i + 1);
        scanf("%d", &n->data);
        pre->next = n;
        pre = n;
    }
    pre->next = NULL;
    return h;
}

void InsertData(Link *h, int m)
{
    Link *pre = h, *n = h;
    int i = 0;

    for(;i < m; i++)
    {
        pre = pre->next;
    }

    n = (Link *)calloc(1, sizeof(Link));
    if(!n)     {printf("No memory!");   exit(0);}
    if(m == 1)
    {
        n->next = h;
    }
    else
    {
        n->next = pre->next;
        pre->next = n;
    }
    printf("Insert %d data is:\n", i + 1);
    scanf("%d", &n->data);
}

int FindData(Link *h, int data)
{
    Link *n = h;
    int i = 1;
    n = n->next;
    while(n->next != NULL)
    {
        if(n->data == data)
        {
            return i;
        }
        n = n->next;
        i++;
    }
    return -1;
}

void DeleteData(Link *h, int m)
{
    Link *pre = h, *n;
    int i = 0;
    for(;i < m ; i++)
    {
        pre = pre->next;
    }
    n = pre->next;
    pre->next = pre->next->next;
    free(n);

}

void DestroyData(Link *h)
{
    Link *pre = h, *n = h;
    while(pre)
    {
        n = pre->next;
        free(pre);
        pre = n;
    }
}
void DisplayData(Link *h)
{
    Link *pre = h;
    int i = 1;
    pre = pre->next;
    while(pre)
    {
        printf("No.%d\n: %d\n", i++, pre->data);
        pre = pre->next;
    }
}


int main()
{
    Link *h;
    int n;
    h = CreadLink(4);
    DisplayData(h);
    InsertData(h, 2);
    DisplayData(h);
    DeleteData(h, 1);
    n = FindData(h, 3);
    printf("          %d\n", n);

    DisplayData(h);
    DestroyData(h);

    return 0;
}
