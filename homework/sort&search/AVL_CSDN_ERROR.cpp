#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
#define LH +1 //左高
#define EH 0  //等高
#define RH -1 //右高

#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define LQ(a,b) ((a) <= (b))

//结点元素类型
typedef struct Student
{
    int key;
    string major;
    Student(){}
    Student(int k,string s) : key(k), major(s){}
}ElementType;

ostream& operator<<(ostream& out, const Student& s)
{
    out<<"("<<s.key<<","<<s.major<<")";
    return out;
}

istream& operator>>(istream& in,Student& s)
{
    in>>s.key>>s.major;
}

typedef int KeyType;//关键字类型

typedef struct AVLNode
{
    ElementType data;
    int bf;
    struct AVLNode* lchild;
    struct AVLNode* rchild;

    AVLNode(){}
    AVLNode(ElementType& e, int ibf=EH, AVLNode* lc=NULL, AVLNode* rc=NULL)
        : data(e), bf(ibf), lchild(lc),rchild(rc){}
}AVLNode, *AVL;


/*
  *Description: 初始化(其实可以不用)
*/
void initAVL(AVL& t)
{
    t = NULL;
}

/*
  *Description: 销毁平衡二叉树
*/
void destroyAVL(AVL& t)
{
    if(t)
    {
        destroyAVL(t->lchild);
        destroyAVL(t->rchild);
        delete t;
        t = NULL;
    }
}
//前序遍历
void preOrderTraverse(AVL t)
{
    if(t)
    {
        cout<<t->data<<" ";
        preOrderTraverse(t->lchild);
        preOrderTraverse(t->rchild);
    }
}

//中序遍历
void inOrderTraverse(AVL t)
{
    if(t)
    {
        inOrderTraverse(t->lchild);
        cout<<t->data<<" ";
        inOrderTraverse(t->rchild);
    }
}

//以前序和中序输出平衡二叉树
void printAVL(AVL t)
{
    cout<<"inOrder: "<<endl;
    inOrderTraverse(t);
    cout<<endl;
    cout<<"preOrder: "<<endl;
    preOrderTraverse(t);
    cout<<endl;
}

/*
  Description:
        在根指针t所指平衡二叉树中递归地查找某关键字等于key的数据元素，
        若查找成功，则返回指向该数据元素结点的指针,否则返回空指针。
        根据需要，也可以返回一个bool值
*/
AVLNode* searchAVL(AVL& t, KeyType key)
{
    if((t == NULL)||EQ(key,t->data.key))
        return t;
    else if LT(key,t->data.key) /* 在左子树中继续查找 */
        return searchAVL(t->lchild,key);
    else
        return searchAVL(t->rchild,key); /* 在右子树中继续查找 */
}
/*
  Description:
        对以*p为根的二叉排序树作左旋处理，处理之后p指向新的树根结点，即旋转
        处理之前的右子树的根结点。也就是书上说说的RR型.
*/
void L_Rotate(AVLNode* &p)
{
    AVLNode * rc = NULL;
    rc = p->rchild;          //rc指向p的右子树根结点
    p->rchild = rc->lchild;//rc的左子树挂接为p的右子树
    rc->lchild = p;
    p = rc;                 //p指向新的根结点
}

/*
  Description:
        对以*p为根的二叉排序树作右旋处理，处理之后p指向新的树根结点，即旋转
        处理之前的左子树的根结点。也就是书上说说的LL型.
*/
void R_Rotate(AVLNode* &p)
{
    AVLNode * lc = NULL;
    lc  = p->lchild;     //lc指向p的左子树根结点
    p->lchild = lc->rchild;   //lc的右子树挂接为p的左子树
    lc->rchild = p;
    p = lc;                 //p指向新的根结点
}

/*对以指针t所指结点为根的二叉树作左平衡旋转处理
    包含LL旋转和LR旋转两种情况
    平衡因子的改变其实很简单，自己画图就出来了
*/
void leftBalance(AVLNode* &t)
{
    AVLNode* lc = NULL;
    AVLNode* rd = NULL;
    lc = t->lchild;
    switch(lc->bf)
    {
        case LH:                    //LL旋转
            t->bf = EH;
            lc->bf = EH;
            R_Rotate(t);
            break;

        case EH:                    //deleteAVL需要，insertAVL用不着
            t->bf = LH;
            lc->bf = RH;
            R_Rotate(t);
            break;

        case RH:                    //LR旋转
            rd = lc->rchild;
            switch(rd->bf)
            {
                case LH:
                    t->bf = RH;
                    lc->bf = EH;
                    break;
                case EH:
                    t->bf = EH;
                    lc->bf = EH;
                    break;
                case RH:
                    t->bf = EH;
                    lc->bf = LH;
                    break;
            }
            rd->bf = EH;
            L_Rotate(t->lchild);//不能写L_Rotate(lc);采用的是引用参数
            R_Rotate(t);
            break;
    }
}

/*对以指针t所指结点为根的二叉树作右平衡旋转处理
    包含RR旋转和RL旋转两种情况
*/
void rightBalance(AVLNode* &t)
{
    AVLNode* rc = NULL;
    AVLNode *ld = NULL;

    rc = t->rchild;
    switch(rc->bf)
    {
        case LH:                //RL旋转
            ld = rc->lchild;
            switch(ld->bf)
            {
                case LH:
                    t->bf = EH;
                    rc->bf = RH;
                    break;
                case EH:
                    t->bf = EH;
                    rc->bf = EH;
                    break;
                case RH:
                    t->bf = LH;
                    rc->bf = EH;
                    break;
            }
            ld->bf = EH;
            R_Rotate(t->rchild);//不能写R_Rotate(rc);采用的是引用参数
            L_Rotate(t);
            break;

        case EH:                //deleteAVL需要，insertAVL用不着
            t->bf = RH;
            rc->bf = LH;
            L_Rotate(t);
            break;

        case RH:                //RR旋转
            t->bf = EH;
            rc->bf = EH;
            L_Rotate(t);
            break;
    }
}

/*
若在平衡的二叉排序树t中不存在和e有相同关键字的结点，则插入一个
数据元素为e的新结点，并返回true，否则返回false。若因插入而使二叉排序树
失去平衡，则作平衡旋转处理，布尔变量taller反映t长高与否
*/
bool insertAVL(AVL& t, ElementType& e, bool& taller)
{
    if(t == NULL)
    {
        t = new AVLNode(e);             //插入元素
        taller = true;
    }
    else
    {
        if(EQ(e.key, t->data.key))       //树中已含该关键字，不插入
        {
            taller = false;
            return false;
        }
        else if(LT(e.key, t->data.key))//在左子树中查找插入点
        {
            if(!insertAVL(t->lchild, e, taller))//左子树插入失败
            {
                return false;
            }
            if(taller)                  //左子树插入成功，且左子树增高
            {
                switch(t->bf)
                {
                    case LH:            //原来t的左子树高于右子树
                        leftBalance(t); //做左平衡处理
                        taller = false;
                        break;
                    case EH:            //原来t的左子树和右子树等高
                        t->bf = LH;      //现在左子树比右子树高
                        taller = true;  //整棵树增高了
                        break;
                    case RH:            //原来t的右子树高于左子树
                        t->bf = EH;      //现在左右子树等高
                        taller = false;
                        break;
                }
            }
        }
        else                            //在右子树中查找插入点
        {
            if(!insertAVL(t->rchild, e, taller))//右子树插入失败
            {
                return false;
            }
            if(taller)                  //右子树插入成功，且右子树增高
            {
                switch(t->bf)
                {
                    case LH:            //原来t的左子树高于右子树
                        t->bf = EH;
                        taller = false;
                        break;
                    case EH:            //原来t的左子树和右子树等高
                        t->bf = RH;
                        taller = true;
                        break;
                    case RH:            //原来t的右子树高于左子树
                        rightBalance(t);//做右平衡处理
                        taller = false;
                        break;
                }
            }
        }
    }
    return true;                        //插入成功
}

/*
若在平衡的二叉排序树t中存在和e有相同关键字的结点，则删除之
并返回true，否则返回false。若因删除而使二叉排序树
失去平衡，则作平衡旋转处理，布尔变量shorter反映t变矮与否
*/
bool deleteAVL(AVL& t, KeyType key, bool& shorter)
{
    if(t == NULL)                       //不存在该元素
    {
        return false;                   //删除失败
    }
    else if(EQ(key, t->data.key))        //找到元素结点
    {
        AVLNode* q = NULL;
        if(t->lchild == NULL)            //左子树为空
        {
            q = t;
            t = t->rchild;
            delete q;
            shorter = true;
        }
        else if(t->rchild == NULL)       //右子树为空
        {
            q = t;
            t = t->lchild;
            delete q;
            shorter = true;
        }
        else                            //左右子树都存在,
        {
            q = t->lchild;
            while(q->rchild)
            {
                q = q->rchild;
            }
            t->data = q->data;
            deleteAVL(t->lchild, q->data.key, shorter);   //在左子树中递归删除前驱结点
        }
    }
    else if(LT(key, t->data.key))        //左子树中继续查找
    {
        if(!deleteAVL(t->lchild, key, shorter))
        {
            return false;
        }
        if(shorter)
        {
            switch(t->bf)
            {
                case LH:
                    t->bf = EH;
                    shorter = true;
                    break;
                case EH:
                    t->bf = RH;
                    shorter = false;
                    break;
                case RH:
                    rightBalance(t);    //右平衡处理
                    if(t->rchild->bf == EH)//注意这里，画图思考一下
                        shorter = false;
                    else
                        shorter = true;
                    break;
            }
        }
    }
    else                                //右子树中继续查找
    {
        if(!deleteAVL(t->rchild, key, shorter))
        {
            return false;
        }
        if(shorter)
        {
            switch(t->bf)
            {
                case LH:
                    leftBalance(t);     //左平衡处理
                    if(t->lchild->bf == EH)//注意这里，画图思考一下
                        shorter = false;
                    else
                        shorter = true;
                    break;
                case EH:
                    t->bf = LH;
                    shorter = false;
                    break;
                case RH:
                    t->bf = EH;
                    shorter = true;
                    break;
            }
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
	AVL t ;
	initAVL(t);
	bool taller = false;
	bool shorter = false;
	int key;
	string major;
	ElementType e;
	int choice = -1;
	bool flag = true;

	while(flag)
	{
		cout<<"--------------------"<<endl;
		cout<<"0. print"<<endl
			<<"1. insert"<<endl
			<<"2. delete"<<endl
			<<"3. search"<<endl
			<<"4. exit"<<endl
			<<"--------------------"<<endl
			<<"please input your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 0:
				printAVL(t);
				cout<<endl<<endl;
				break;
			case 1:
				inOrderTraverse(t);
				cout<<endl<<"input the elements to be inserted,end by 0:"<<endl;
				while(cin>>key && key)
				{
					major="CS";
					ElementType e(key,major);
					if(insertAVL(t,e,taller))

					{
						cout<<"insert element "<<e<<" successfully"<<endl;
					}
					else
					{
						cout<<"there already exists an element with key "<< e.key<<endl;
					}
				}
				//while(cin>>e && e.key)
//				{
//					if(insertAVL(t,e,taller))
//					{
//						cout<<"insert element "<<e<<" successfully"<<endl;
//					}
//					else
//					{
//						cout<<"there already exists an element with key "<< e.key<<endl;
//					}
//				}
				cout<<"after insert: "<<endl;
				printAVL(t);
				cout<<endl<<endl;
				break;

			case 2:
				inOrderTraverse(t);
				cout<<endl<<"input the keys to be deleted,end by 0:"<<endl;
				while(cin>>key && key)
				{
					if(deleteAVL(t,key,shorter))
					{
						cout<<"delete the element with key "<<key<<" successfully"<<endl;
					}
					else
					{
						cout<<"no such an element with key "<<key<<endl;
					}
				}
				cout<<"after delete: "<<endl;
				printAVL(t);
				cout<<endl<<endl;
				break;

			case 3:
				inOrderTraverse(t);
				cout<<endl<<"input the keys to be searched,end by 0:"<<endl;
				while(cin>>key && key)
				{
					if(searchAVL(t,key))
						cout<<key<<" is in the tree"<<endl;
					else
						cout<<key<<" is not in the tree"<<endl;
				}
				cout<<endl<<endl;
				break;

			case 4:
				flag = false;
				break;

			default:
				cout<<"error! watch and input again!"<<endl<<endl;

		}
	}
	destroyAVL(t);

    system("PAUSE");
    return EXIT_SUCCESS;
}
//    BBTree bst;
//    int a[]= { 1,2,3,4,5, 10,9,8,7,6};
//    for(auto i : a)
//        bst.insert_BBT(i);
//
//    bst.delete_BBT(5);
//    bst.dispaly();
//    cout << endl<< endl;
//    bst.delete_BBT(4);
//    bst.dispaly();
//    cout << endl<< endl;
//    bst.delete_BBT(9);
//    bst.dispaly();
//    cout << endl<< endl;
//    bst.delete_BBT(1);