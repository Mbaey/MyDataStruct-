#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define INFINITY_VALUE 65535
#define MAX_NUM 20
//参考网页: http://blog.csdn.net/sysu_arui/article/details/7897017

typedef int NodeType;
typedef int Status;
struct AVLNode
{
    NodeType value=0;
    int bf=0; //平衡因子
    AVLNode *lchild=NULL, *rchild=NULL;
    AVLNode()=default;
    AVLNode(NodeType d, AVLNode *r, AVLNode *l):value(d),lchild(l),rchild(r) {};
    AVLNode(NodeType d, AVLNode *r, AVLNode *l, int b):value(d), bf(b),lchild(l),rchild(r) {};
    AVLNode(NodeType d):value(d) {};
    ~AVLNode()
    {
//        cout << "delete " << value << endl;
    };

    void display()
    {
        cout << "v:" << value << "  bf:"<<bf<<" \t";
    }

    Status cmp(AVLNode *b)
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

struct BBTree //Balanced Binary Tree
{
    AVLNode *root=NULL;
    BBTree()=default;
    ~BBTree()
    {
        AVLNode *p = root, *q=NULL;
        stack<AVLNode *> sta;
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

    bool search_BST(NodeType e, AVLNode **res, AVLNode **find)
    {
        AVLNode *p = root, *f=root;
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
        in_order(root);
        cout << endl<< "前序遍历：\t";
        pre_order(root);
        cout << endl;
    }
    int getLevel()
    {
        return getLevel(root);
    }

    /*
    1.e存在相同节点。 return false
    2.插入，isTaller表示是否长高
    如果失去平衡，转。。。。
    */
    bool insert_BBT(NodeType e)
    {
        bool isTaller=false;
        return insert_BBT(&root, e, isTaller);
    }

    /*如果寻找到被删的节点

    1.该节点有左右孩子  -》 放到左子树 的 最右端
    2.该节点有左孩子    -》 把左孩子 赋值 给他爸
    3.该节点有右孩子    -》 把右孩子 赋值 给他爸
    4.该节点沒有左右孩子 -》直接删
    */
    bool delete_BST(NodeType e)
    {
        AVLNode *f=NULL, *p=NULL, *q=NULL;
        if(search_BST(e, &f, &p)) // exist
        {
            AVLNode *right=p->rchild, *left=p->lchild;
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

    bool delete_BBT(NodeType e)
    {
        bool isShorter=false;
        return delete_BBT(root, e, isShorter);
    }
private:
    static const int EH=0, LH=1, RH=-1;
    int getLevel(AVLNode * p)
    {
        if(p==NULL)
        {
            return 0;
        }
        else
        {
            return max(1+getLevel(p->lchild), 1+getLevel(p->rchild));
        }
    }

    void in_order(AVLNode *p)
    {
        if(p)
        {
            in_order(p->lchild);
            p->display();
            in_order(p->rchild);
        }
    }
    void pre_order(AVLNode *p)
    {
        if(p)
        {
            p->display();
            pre_order(p->lchild);
            pre_order(p->rchild);
        }
    }

    void R_Rotate(AVLNode **p) //LL型， 顺时针转
    {
        AVLNode *lc= (*p)->lchild;
        (*p)->lchild = lc->rchild;
        lc->rchild = *p;
        *p=lc;
    }
    void L_Rotate(AVLNode **p) //RR型， 逆时针转
    {
        AVLNode *rc=(*p)->rchild;
        (*p)->rchild = rc->lchild;
        rc->lchild = *p;
        *p=rc;
    }
    void RightBalance(AVLNode **T) //RR型， 逆时针转
    {
        AVLNode *rc = (*T)->rchild, *ld=NULL;
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
        case EH:                //deleteAVL需要，insertAVL用不着
            (*T)->bf = RH;
            rc->bf = LH;
            L_Rotate(T);
            break;
        case RH:
            (*T)->bf= rc->bf=EH;
            L_Rotate(T);
        }
    }

    void LeftBalance(AVLNode **T) //RR型， 逆时针转
    {
        AVLNode *lc = (*T)->lchild, *rd=NULL;
        switch(lc->bf)
        {
        case LH:
            (*T)->bf= lc->bf=EH;
            R_Rotate(T);
            break;
        case EH:                    //deleteAVL需要，insertAVL用不着
            (*T)->bf = LH;
            lc->bf = RH;
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
            L_Rotate(&((*T)->lchild));//不能写L_Rotate(lc);采用的是引用参数
            R_Rotate(T);
        }
    }

    bool insert_BBT(AVLNode **T, NodeType e, bool &isTaller)
    {
        if( !*T ) //*T==NULL
        {
            *T = new AVLNode(e, NULL, NULL, 0);
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
                if(!insert_BBT(& ((*T)->rchild), e, isTaller)) return false;
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
                if(!insert_BBT(& ((*T)->lchild), e, isTaller)) return false;
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
    //删成功了返回成功， isShorter也为true
//    bool deleteAVL(AVL& t, KeyType key, bool& shorter)
//    以前不知道可以这么写啊。。。。 双重指针才能改f->lchild 累死了。
    bool delete_BBT(AVLNode *&T, NodeType e, bool &isShorter)
    {
        if(T == NULL)
        {
            isShorter=false;
            return false;
        }
        else
        {
            if(T->EQ(e))
            {
                /*删除该节点*/
                //还要改变bf
                AVLNode *right=T->rchild, *left=T->lchild, *p=T;

                if( !right )
                {
                    T=left;
                    delete p;
                    isShorter=true;
                }
                else if( !left)
                {
                    T=right;
                    delete p;
                    isShorter=true;
                }
                else if(left && right )
                {
//                    AVLNode *nowF = p;
                    AVLNode *q = left;
                    while(q->rchild)
                    {
//                        nowF=q;
                        q=q->rchild;
                    }
                    p->value = q->value;//
//                    t->data = q->data;
                    delete_BBT(p->lchild, q->value, isShorter);   //在左子树中递归删除前驱结点
                }

                /**/
                return true;
            }
            if(T->RT(e)) // a < e, 进入右子树
            {
                if(!delete_BBT(T->rchild, e, isShorter)) return false;
                if(isShorter)
                {
                    switch(T->bf)
                    {
                    case LH:
                        LeftBalance(&T);     //左平衡处理
                        if(T->lchild->bf == EH)//注意这里，画图思考一下
                            isShorter = false;
                        else
                            isShorter = true;
                        break;
                    case EH:
                        T->bf = LH;
                        isShorter = false;
                        break;
                    case RH:
                        T->bf = EH;
                        isShorter = true;
                        break;
//                    case LH:
//                        LeftBalance(T);
//                        if( T->lchild->bf == EH)//注意这里，画图思考一下
//                            isShorter = false;
//                        else
//                            isShorter = true;
//
//                        break;
//                    case EH:
//                        T->bf=LH;
//                        isShorter=false;
//                        break;
//                    case RH:
//                        T->bf=EH;
//                        isShorter=true;
//                        break;
                    }
                }
            }
            else
            {
                if(!delete_BBT(T->lchild, e, isShorter)) return false;
                if(isShorter)
                {
                    switch(T->bf)
                    {

                    case LH:
                        T->bf = EH;
                        isShorter = true;
                        break;
                    case EH:
                        T->bf = RH;
                        isShorter = false;
                        break;
                    case RH:
                        RightBalance(&T);    //右平衡处理
                        if(T->rchild->bf == EH)//注意这里，画图思考一下
                            isShorter = false;
                        else
                            isShorter = true;
                        break;
//                    case LH:
//                        T->bf=EH;
//                        isShorter=true;
//                        break;
//                    case EH:
//                        T->bf=RH;
//                        isShorter=false;
//                        break;
//                    case RH:
//                        RightBalance(T);
//                        if( T->rchild->bf == EH)//注意这里，画图思考一下
//                            isShorter = false;
//                        else
//                            isShorter = true;
//                        break;
                    }
                }
            }

        }
        return true;
    }
};


int main()
{
    BBTree bst;
    int a[]= { 1,2,3,4,5, 10,9,8,7,6};
    for(auto i : a)
        bst.insert_BBT(i);


    bst.dispaly();
    cout << endl<< endl;
//    cout << bst.getLevel()<< endl;
    bst.delete_BBT(5);
    bst.dispaly();
    cout << endl<< endl;
    bst.delete_BBT(4);
    bst.dispaly();
    cout << endl<< endl;
    bst.delete_BBT(9);
    bst.dispaly();
    cout << endl<< endl;
    bst.delete_BBT(1);
    //还是不对。。。
    cout << bst.getLevel()<< endl;
    bst.dispaly();
    cout << endl<< endl;
    return 0;
}
