#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef struct abc
{
    int data;
    struct abc *lc, *rc;
}tree;

void creattree(tree *t, int level)
{
    int c;
    printf("input No.%d number!\n", level);
    scanf("%d", &c);
    if(!c) t = NULL;
    else
    {
        t = (tree *)malloc(sizeof(tree));
        t->data = c;
        creattree(t->lc, level + 1);
        creattree(t->rc, level + 1);
    }

}

void visit(int a, int level)
{
    if(a==10)
        printf("%d is found in No.%d level\n", a, level);
}

void PreOrderTree(tree *head, int level)
{
    if(head)
    {
        printf("No.%d level's number is:%d", level, head->data);
        PreOrderTree(head->lc, level + 1);
        PreOrderTree(head->rc, level + 1);
    }
}

void DeleteTree(tree *t)
{

    if(t)
    {
        DeleteTree(t->lc);
        DeleteTree(t->rc);
        free(t);
    }
}
int main()
{
    int level = 1;
    tree *T = NULL;
    creattree(T, level);
    PreOrderTree(T, level);
    DeleteTree(T);

    return 0;
}
