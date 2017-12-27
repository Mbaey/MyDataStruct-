#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
#define LH +1 //���
#define EH 0  //�ȸ�
#define RH -1 //�Ҹ�

#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define LQ(a,b) ((a) <= (b))

//���Ԫ������
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

typedef int KeyType;//�ؼ�������

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
  *Description: ��ʼ��(��ʵ���Բ���)
*/
void initAVL(AVL& t)
{
    t = NULL;
}

/*
  *Description: ����ƽ�������
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
//ǰ�����
void preOrderTraverse(AVL t)
{
    if(t)
    {
        cout<<t->data<<" ";
        preOrderTraverse(t->lchild);
        preOrderTraverse(t->rchild);
    }
}

//�������
void inOrderTraverse(AVL t)
{
    if(t)
    {
        inOrderTraverse(t->lchild);
        cout<<t->data<<" ";
        inOrderTraverse(t->rchild);
    }
}

//��ǰ����������ƽ�������
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
        �ڸ�ָ��t��ָƽ��������еݹ�ز���ĳ�ؼ��ֵ���key������Ԫ�أ�
        �����ҳɹ����򷵻�ָ�������Ԫ�ؽ���ָ��,���򷵻ؿ�ָ�롣
        ������Ҫ��Ҳ���Է���һ��boolֵ
*/
AVLNode* searchAVL(AVL& t, KeyType key)
{
    if((t == NULL)||EQ(key,t->data.key))
        return t;
    else if LT(key,t->data.key) /* ���������м������� */
        return searchAVL(t->lchild,key);
    else
        return searchAVL(t->rchild,key); /* ���������м������� */
}
/*
  Description:
        ����*pΪ���Ķ�����������������������֮��pָ���µ�������㣬����ת
        ����֮ǰ���������ĸ���㡣Ҳ��������˵˵��RR��.
*/
void L_Rotate(AVLNode* &p)
{
    AVLNode * rc = NULL;
    rc = p->rchild;          //rcָ��p�������������
    p->rchild = rc->lchild;//rc���������ҽ�Ϊp��������
    rc->lchild = p;
    p = rc;                 //pָ���µĸ����
}

/*
  Description:
        ����*pΪ���Ķ�����������������������֮��pָ���µ�������㣬����ת
        ����֮ǰ���������ĸ���㡣Ҳ��������˵˵��LL��.
*/
void R_Rotate(AVLNode* &p)
{
    AVLNode * lc = NULL;
    lc  = p->lchild;     //lcָ��p�������������
    p->lchild = lc->rchild;   //lc���������ҽ�Ϊp��������
    lc->rchild = p;
    p = lc;                 //pָ���µĸ����
}

/*����ָ��t��ָ���Ϊ���Ķ���������ƽ����ת����
    ����LL��ת��LR��ת�������
    ƽ�����ӵĸı���ʵ�ܼ򵥣��Լ���ͼ�ͳ�����
*/
void leftBalance(AVLNode* &t)
{
    AVLNode* lc = NULL;
    AVLNode* rd = NULL;
    lc = t->lchild;
    switch(lc->bf)
    {
        case LH:                    //LL��ת
            t->bf = EH;
            lc->bf = EH;
            R_Rotate(t);
            break;

        case EH:                    //deleteAVL��Ҫ��insertAVL�ò���
            t->bf = LH;
            lc->bf = RH;
            R_Rotate(t);
            break;

        case RH:                    //LR��ת
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
            L_Rotate(t->lchild);//����дL_Rotate(lc);���õ������ò���
            R_Rotate(t);
            break;
    }
}

/*����ָ��t��ָ���Ϊ���Ķ���������ƽ����ת����
    ����RR��ת��RL��ת�������
*/
void rightBalance(AVLNode* &t)
{
    AVLNode* rc = NULL;
    AVLNode *ld = NULL;

    rc = t->rchild;
    switch(rc->bf)
    {
        case LH:                //RL��ת
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
            R_Rotate(t->rchild);//����дR_Rotate(rc);���õ������ò���
            L_Rotate(t);
            break;

        case EH:                //deleteAVL��Ҫ��insertAVL�ò���
            t->bf = RH;
            rc->bf = LH;
            L_Rotate(t);
            break;

        case RH:                //RR��ת
            t->bf = EH;
            rc->bf = EH;
            L_Rotate(t);
            break;
    }
}

/*
����ƽ��Ķ���������t�в����ں�e����ͬ�ؼ��ֵĽ�㣬�����һ��
����Ԫ��Ϊe���½�㣬������true�����򷵻�false����������ʹ����������
ʧȥƽ�⣬����ƽ����ת������������taller��ӳt�������
*/
bool insertAVL(AVL& t, ElementType& e, bool& taller)
{
    if(t == NULL)
    {
        t = new AVLNode(e);             //����Ԫ��
        taller = true;
    }
    else
    {
        if(EQ(e.key, t->data.key))       //�����Ѻ��ùؼ��֣�������
        {
            taller = false;
            return false;
        }
        else if(LT(e.key, t->data.key))//���������в��Ҳ����
        {
            if(!insertAVL(t->lchild, e, taller))//����������ʧ��
            {
                return false;
            }
            if(taller)                  //����������ɹ���������������
            {
                switch(t->bf)
                {
                    case LH:            //ԭ��t������������������
                        leftBalance(t); //����ƽ�⴦��
                        taller = false;
                        break;
                    case EH:            //ԭ��t�����������������ȸ�
                        t->bf = LH;      //��������������������
                        taller = true;  //������������
                        break;
                    case RH:            //ԭ��t������������������
                        t->bf = EH;      //�������������ȸ�
                        taller = false;
                        break;
                }
            }
        }
        else                            //���������в��Ҳ����
        {
            if(!insertAVL(t->rchild, e, taller))//����������ʧ��
            {
                return false;
            }
            if(taller)                  //����������ɹ���������������
            {
                switch(t->bf)
                {
                    case LH:            //ԭ��t������������������
                        t->bf = EH;
                        taller = false;
                        break;
                    case EH:            //ԭ��t�����������������ȸ�
                        t->bf = RH;
                        taller = true;
                        break;
                    case RH:            //ԭ��t������������������
                        rightBalance(t);//����ƽ�⴦��
                        taller = false;
                        break;
                }
            }
        }
    }
    return true;                        //����ɹ�
}

/*
����ƽ��Ķ���������t�д��ں�e����ͬ�ؼ��ֵĽ�㣬��ɾ��֮
������true�����򷵻�false������ɾ����ʹ����������
ʧȥƽ�⣬����ƽ����ת������������shorter��ӳt�䰫���
*/
bool deleteAVL(AVL& t, KeyType key, bool& shorter)
{
    if(t == NULL)                       //�����ڸ�Ԫ��
    {
        return false;                   //ɾ��ʧ��
    }
    else if(EQ(key, t->data.key))        //�ҵ�Ԫ�ؽ��
    {
        AVLNode* q = NULL;
        if(t->lchild == NULL)            //������Ϊ��
        {
            q = t;
            t = t->rchild;
            delete q;
            shorter = true;
        }
        else if(t->rchild == NULL)       //������Ϊ��
        {
            q = t;
            t = t->lchild;
            delete q;
            shorter = true;
        }
        else                            //��������������,
        {
            q = t->lchild;
            while(q->rchild)
            {
                q = q->rchild;
            }
            t->data = q->data;
            deleteAVL(t->lchild, q->data.key, shorter);   //���������еݹ�ɾ��ǰ�����
        }
    }
    else if(LT(key, t->data.key))        //�������м�������
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
                    rightBalance(t);    //��ƽ�⴦��
                    if(t->rchild->bf == EH)//ע�������ͼ˼��һ��
                        shorter = false;
                    else
                        shorter = true;
                    break;
            }
        }
    }
    else                                //�������м�������
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
                    leftBalance(t);     //��ƽ�⴦��
                    if(t->lchild->bf == EH)//ע�������ͼ˼��һ��
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