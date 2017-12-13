#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define INFINITY_VALUE 65535
#define MAX_NUM 20

typedef int NodeType;
typedef int Status;
struct BSTNode
{
    NodeType value=0;
    int bf=0; //平衡因子
    BSTNode *rchild=NULL, *lchild=NULL;
    BSTNode()=default;
    BSTNode(NodeType d, BSTNode *r, BSTNode *l):value(d),rchild(r),lchild(l) {};
    BSTNode(NodeType d, BSTNode *r, BSTNode *l, int b):value(d), bf(b),rchild(r),lchild(l) {};
    BSTNode(NodeType d):value(d) {};
    ~BSTNode()
    {
        cout << "delete " << value << endl;
    };

    void display()
    {
        cout << value << " \t";
    }

    Status cmp(BSTNode *b)
    {
        if(value == b->value)
        {
            return 0;
        }
        else if(value > b->value)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    bool EQ(NodeType b)
    {
        if(value == b)
            return true;
        else
            return false;
    }
    bool RT(NodeType b)  // a 比 b 小 往右走
    {
        if(value < b)
            return true;
        else
            return false;
    }
};

struct BSTree
{
    BSTNode *root=NULL;
    BSTree()=default;
    ~BSTree()
    {
        BSTNode *p = root, *q=NULL;
        stack<BSTNode *> sta;
        while(p!=NULL)
        {
            if(p->rchild != NULL) sta.push(p->rchild);
            q = p;
            p = p->lchild;
//            cout << "刪除了" << q->value << endl;
            delete q;
            if(p==NULL)
            {
                if(sta.empty())
                {
                    break;
                }
                else
                {
                    p = sta.top();
                    sta.pop();
                }
            }
        }
    }

    bool search_BST(NodeType e, BSTNode **res, BSTNode **find)
    {
        BSTNode *p = root, *f=root;
        while(p!=NULL && !p->EQ(e))
        {
            if(p->RT(e))
            {
                f=p;
                p=p->rchild;
            }
            else
            {
                f=p;
                p=p->lchild;
            }
        }
        if(p==NULL)
        {
            *res=f, find=NULL;
            return false;
        }
        else
        {
            *res=f;
            *find=p;
            return true;
        }
    }

    void dispaly()
    {
        cout <<"Binary Sort Tree:\t";
        dispaly(root);
        cout << endl;
    }
    int getLevel(){
        return getLevel(root);
    }

    /*
    1.e存在相同节点。 return false
    2.插入，isTaller表示是否长高
    如果失去平衡，转。。。。
    */
    bool insert_BST(NodeType e)
    {
        bool isTaller=false;
        return insert_BST(&root, e, isTaller);
    }

    /*如果寻找到被删的节点

    1.该节点有左右孩子  -》 放到左子树 的 最右端
    2.该节点有左孩子    -》 把左孩子 赋值 给他爸
    3.该节点有右孩子    -》 把右孩子 赋值 给他爸
    4.该节点沒有左右孩子 -》直接删
    */
    bool delete_BST(NodeType e)
    {
        BSTNode *f=NULL, *p=NULL, *q=NULL;
        if(search_BST(e, &f, &p)) // exist
        {
            BSTNode *right=p->rchild, *left=p->lchild;
            if(!right && !left)
            {
                //f < p  p is in right
                if(f->RT(e)) f->rchild=NULL;
                else f->lchild=NULL;
                delete p;
            }
            else if(left && right )
            {
                f=p;
                q = left;
                while(q->rchild)
                {
                    f=q;
                    q=q->rchild;
                }
                p->value = q->value;
                if(f != p)  f->rchild = q->lchild;
                else f->lchild = q->lchild;
                delete q;
            }
            else if( !right )
            {
                if(f->RT(e)) f->rchild=right;
                else f->lchild=right;
                delete p;
            }
            else if( !left)
            {
                if(f->RT(e)) f->rchild=right;
                else f->lchild=right;
                delete p;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
private:
    static const int EH=0, LH=1, RH=-1;
    int getLevel(BSTNode * p){
        if(p==NULL){
            return 0;
        }else{
            return max(1+getLevel(p->lchild), 1+getLevel(p->rchild));
        }
    }

    void dispaly(BSTNode *p)
    {
        if(p)
        {
            dispaly(p->lchild);
            p->display();
            dispaly(p->rchild);
        }
    }

    void R_Rotate(BSTNode **p) //LL型， 顺时针转
    {
        BSTNode *lc= (*p)->lchild;
        (*p)->lchild = lc->rchild;
        lc->rchild = *p;
        *p=lc;
    }
    void L_Rotate(BSTNode **p) //RR型， 逆时针转
    {
        BSTNode *rc=(*p)->rchild;
        (*p)->rchild = rc->lchild;
        rc->lchild = *p;
        *p=rc;
    }
    void RightBalance(BSTNode **T) //RR型， 逆时针转
    {
        BSTNode *rc = (*T)->rchild, *ld=NULL;
        switch(rc->bf)
        {
        case LH:

            ld = rc->lchild;
            switch(ld->bf)
            {
            case LH:
                (*T)->bf=EH;
                rc->bf=RH;
                break;
            case EH:
                (*T)->bf=EH;
                rc->bf=EH;
                break;
            case RH:
                (*T)->bf=LH;
                rc->bf=EH;
                break;
            }
            ld->bf=EH;
            R_Rotate(&((*T)->rchild));
            L_Rotate(T);

            break;
        case RH:
            (*T)->bf= rc->bf=EH;
            L_Rotate(T);
        }
    }

    void LeftBalance(BSTNode **T) //RR型， 逆时针转
    {
        BSTNode *lc = (*T)->lchild, *rd=NULL;
        switch(lc->bf)
        {
        case LH:
            (*T)->bf= lc->bf=EH;
            R_Rotate(T);
            break;
        case RH:
            rd = lc->rchild;
            switch(rd->bf)
            {
            case LH:
                (*T)->bf=RH;
                lc->bf=EH;
                break;
            case EH:
                (*T)->bf=EH;
                lc->bf=EH;
                break;
            case RH:
                (*T)->bf=EH;
                lc->bf=LH;
                break;
            }
            rd->bf=EH;
            L_Rotate(&((*T)->lchild));
            R_Rotate(T);
        }
    }

    bool insert_BST(BSTNode **T, NodeType e, bool &isTaller)
    {
        if( !*T ) //*T==NULL
        {
            *T = new BSTNode(e, NULL, NULL, 0);
            isTaller=true;
            return true;
        }
        else
        {
            if((*T)->EQ(e))
            {
                isTaller=false;
                return false;
            }
            if((*T)->RT(e)) // a < e, 进入右子树
            {
                if(!insert_BST(& ((*T)->rchild), e, isTaller)) return false;
                if(isTaller)
                {
                    switch((*T)->bf)
                    {
                    case LH:
                        (*T)->bf=EH;
                        isTaller=false;
                        break;
                    case EH:
                        (*T)->bf=RH;
                        isTaller=true;
                        break;
                    case RH:
                        RightBalance(T);
                        isTaller=false;
                        break;
                    }
                }
            }
            else
            {
                if(!insert_BST(& ((*T)->lchild), e, isTaller)) return false;
                if(isTaller)
                {
                    switch((*T)->bf)
                    {
                    case LH:
                        LeftBalance(T);
                        isTaller=false;
                        break;
                    case EH:
                        (*T)->bf=LH;
                        isTaller=true;
                        break;
                    case RH:
                        (*T)->bf=EH;
                        isTaller=false;
                        break;
                    }
                }
            }

        }
        return true;
    }

};


int main()
{
    BSTree bst;
    int a[]= { 1,2,3,4,5, 10 ,9,8,7,6};
    for(auto i : a)
        bst.insert_BST(i);


    bst.dispaly();
    cout << bst.getLevel()<< endl;
//    bst.delete_BST(53);
//    bst.delete_BST(45);
//    bst.delete_BST(90);
//    bst.dispaly();
    return 0;
}
