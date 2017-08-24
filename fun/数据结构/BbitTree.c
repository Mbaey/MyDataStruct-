#include <stdio.h>
#include <stdlib.h>

typedef char elemtype ;

typedef struct tree
{
    elemtype data;
    struct tree *rchild, *lchild;
}T;
//1.创建一颗树
//2.遍历一颗树
//3.销毁一颗树
void InitTree(T **h, int level)
{
    elemtype ch;
    printf("please input a data in %d level:\n", level);
    scanf("%c", &ch);
    getchar();

    if(ch != ' ')
    {
        *h = (T*)malloc(sizeof(T));
        if(!*h)  {exit(0);}
//        (*h)->lchild = NULL;
//        (*h)->rchild = NULL;

        (*h)->data = ch;
        InitTree(&(*h)->lchild, level + 1);
        InitTree(&(*h)->rchild, level + 1);
    }
    else
    {
        *h = NULL;
    }

}

void Visit(T *h, int level)
{
    printf("the data in the %d level is %c:\n", level, h->data);
}

void SearchTree(T *h, int level)
{
    if(h!=NULL)
    {
        Visit(h, level);
        SearchTree(h->lchild, level + 1);
        SearchTree(h->rchild, level + 1);
    }


//    Visit(h, level);
//    if(!h->lchild)
//        SearchTree(h->lchild, level + 1);
//    if(!h->rchild)
//        SearchTree(h->rchild, level + 1);
}

void DestroyTree(T **h)
{
    if ( *h != NULL )
    {
        DestroyTree( &( (*h)->lchild) );
        DestroyTree( &( (*h)->rchild) );
        free( *h );
        *h = NULL;
    }

//    if(!h->lchild)
//        DestroyTree(h->lchild);
//    if(!h->rchild)
//        DestroyTree(h->rchild);
//    free(h);
}

int main()
{
    T *h = NULL;

    InitTree(&h, 1);

    SearchTree(h, 1);
    DestroyTree(&h);
    return 0;
}
