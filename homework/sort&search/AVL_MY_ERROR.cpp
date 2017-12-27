#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define INFINITY_VALUE 65535
#define MAX_NUM 20
//�ο���ҳ: http://blog.csdn.net/sysu_arui/article/details/7897017

typedef int NodeType;
typedef int Status;
struct AVLNode
{
    NodeType value=0;
    int bf=0; //ƽ������
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
    bool RT(NodeType b)  // a �� b С ������
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
//            cout << "�h����" << q->value << endl;
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
        cout << endl<< "ǰ�������\t";
        pre_order(root);
        cout << endl;
    }
    int getLevel()
    {
        return getLevel(root);
    }

    /*
    1.e������ͬ�ڵ㡣 return false
    2.���룬isTaller��ʾ�Ƿ񳤸�
    ���ʧȥƽ�⣬ת��������
    */
    bool insert_BBT(NodeType e)
    {
        bool isTaller=false;
        return insert_BBT(&root, e, isTaller);
    }

    /*���Ѱ�ҵ���ɾ�Ľڵ�

    1.�ýڵ������Һ���  -�� �ŵ������� �� ���Ҷ�
    2.�ýڵ�������    -�� ������ ��ֵ ������
    3.�ýڵ����Һ���    -�� ���Һ��� ��ֵ ������
    4.�ýڵ�]�����Һ��� -��ֱ��ɾ
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

    void R_Rotate(AVLNode **p) //LL�ͣ� ˳ʱ��ת
    {
        AVLNode *lc= (*p)->lchild;
        (*p)->lchild = lc->rchild;
        lc->rchild = *p;
        *p=lc;
    }
    void L_Rotate(AVLNode **p) //RR�ͣ� ��ʱ��ת
    {
        AVLNode *rc=(*p)->rchild;
        (*p)->rchild = rc->lchild;
        rc->lchild = *p;
        *p=rc;
    }
    void RightBalance(AVLNode **T) //RR�ͣ� ��ʱ��ת
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
        case EH:                //deleteAVL��Ҫ��insertAVL�ò���
            (*T)->bf = RH;
            rc->bf = LH;
            L_Rotate(T);
            break;
        case RH:
            (*T)->bf= rc->bf=EH;
            L_Rotate(T);
        }
    }

    void LeftBalance(AVLNode **T) //RR�ͣ� ��ʱ��ת
    {
        AVLNode *lc = (*T)->lchild, *rd=NULL;
        switch(lc->bf)
        {
        case LH:
            (*T)->bf= lc->bf=EH;
            R_Rotate(T);
            break;
        case EH:                    //deleteAVL��Ҫ��insertAVL�ò���
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
            L_Rotate(&((*T)->lchild));//����дL_Rotate(lc);���õ������ò���
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
            if((*T)->RT(e)) // a < e, ����������
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
    //ɾ�ɹ��˷��سɹ��� isShorterҲΪtrue
//    bool deleteAVL(AVL& t, KeyType key, bool& shorter)
//    ��ǰ��֪��������ôд���������� ˫��ָ����ܸ�f->lchild �����ˡ�
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
                /*ɾ���ýڵ�*/
                //��Ҫ�ı�bf
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
                    delete_BBT(p->lchild, q->value, isShorter);   //���������еݹ�ɾ��ǰ�����
                }

                /**/
                return true;
            }
            if(T->RT(e)) // a < e, ����������
            {
                if(!delete_BBT(T->rchild, e, isShorter)) return false;
                if(isShorter)
                {
                    switch(T->bf)
                    {
                    case LH:
                        LeftBalance(&T);     //��ƽ�⴦��
                        if(T->lchild->bf == EH)//ע�������ͼ˼��һ��
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
//                        if( T->lchild->bf == EH)//ע�������ͼ˼��һ��
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
                        RightBalance(&T);    //��ƽ�⴦��
                        if(T->rchild->bf == EH)//ע�������ͼ˼��һ��
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
//                        if( T->rchild->bf == EH)//ע�������ͼ˼��һ��
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
    //���ǲ��ԡ�����
    cout << bst.getLevel()<< endl;
    bst.dispaly();
    cout << endl<< endl;
    return 0;
}
