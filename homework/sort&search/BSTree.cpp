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
struct BSTNode{
    NodeType value=0;
    int bf=0; //ƽ������
    BSTNode *rchild=NULL, *lchild=NULL;
    BSTNode()=default;
    BSTNode(NodeType d, BSTNode *r, BSTNode *l):value(d),rchild(r),lchild(l){};
    BSTNode(NodeType d):value(d){};
    ~BSTNode(){
        cout << "delete " << value << endl;
    };

    void display(){
        cout << value << " \t";
    }

    Status cmp(BSTNode *b){
        if(value == b->value){
            return 0;
        }else if(value > b->value){
            return 1;
        }else{
            return -1;
        }
    }

    bool EQ(NodeType b){
        if(value == b)
            return true;
        else
            return false;
    }
    bool RT(NodeType b){ // a �� b С ������
        if(value < b)
            return true;
        else
            return false;
    }
};

struct BSTree{
    BSTNode *root=NULL;
    BSTree()=default;
    ~BSTree(){
        BSTNode *p = root, *q=NULL; stack<BSTNode *> sta;
        while(p!=NULL){
            if(p->rchild != NULL) sta.push(p->rchild);
            q = p;
            p = p->lchild;
//            cout << "�h����" << q->value << endl;
            delete q;
            if(p==NULL){
                if(sta.empty()){ break; }
                else{
                    p = sta.top();
                    sta.pop();
                }
            }
        }
    }

    bool search_BST(NodeType e, BSTNode **res, BSTNode **find){
        BSTNode *p = root, *f=root;
        while(p!=NULL && !p->EQ(e)){
            if(p->RT(e)){ f=p; p=p->rchild; }
            else{ f=p; p=p->lchild; }
        }
        if(p==NULL) {*res=f, find=NULL;   return false;}
        else { *res=f; *find=p;   return true;}
    }

    void dispaly(){
        cout <<"Binary Sort Tree:\t";
        dispaly(root);
        cout << endl;
    }

    bool insert_BST(NodeType e){
        BSTNode *f=NULL, *p=NULL;
        if(search_BST(e, &f, &p)){
            return false;// exist
        }else{
            BSTNode *p=new BSTNode(e);
            if(!f) root=p;
            else if(  f->RT(e) ) f->rchild=p;
            else f->lchild=p;
            return true;
        }
    }
    /*���Ѱ�ҵ���ɾ�Ľڵ�

    1.�ýڵ������Һ���  -�� �ŵ������� �� ���Ҷ�
    2.�ýڵ�������    -�� ������ ��ֵ ������
    3.�ýڵ����Һ���    -�� ���Һ��� ��ֵ ������
    4.�ýڵ�]�����Һ��� -��ֱ��ɾ
    */
	/*
	http://blog.csdn.net/sysu_arui/article/details/7865864
	3��ɾ��
	�ڶ����������ɾ��һ�������Ľ��p���������
	(1)  ���p��������������ֱ��ɾ���ý�㣬�޸ĸ��ڵ���Ӧָ��
	(2)  ���p�����������������������p�������������������ӵ�p�ĸ��ڵ���
	(3)  ��������ͬʱ���ڣ��������ִ���ʽ
	a.      �ҵ����p������ֱ��ǰ�����s���ѽ��s������ת�Ƶ����p��Ȼ��ɾ�����s�����ڽ��sΪp�������������ҵĽ�㣬���s����������ɾ�����s���Թ�ᵽ���(2)����ε�����ݽṹP230-231���Ǹô���ʽ��
	b.     �ҵ����p������ֱ�Ӻ�̽��s���ѽ��s������ת�Ƶ����p��Ȼ��ɾ�����s�����ڽ��sΪp��������������Ľ�㣬���s����������ɾ�����s���Թ�ᵽ���(2)���㷨���۵�2��P156-157���Ǹô���ʽ��
	c.      �ҵ�p������ֱ��ǰ��s����p���������ӵ����ڵ��ϣ���p���������ӵ�s���������ϣ�Ȼ��ɾ�����p��
	*/
    bool delete_BST(NodeType e){
        BSTNode *f=NULL, *p=NULL, *q=NULL;
        if(search_BST(e, &f, &p)){// exist
            BSTNode *right=p->rchild, *left=p->lchild;
            if(!right && !left){
                    //f < p  p is in right
                if(f->RT(e)) f->rchild=NULL;
                else f->lchild=NULL;
                delete p;
            }else if(left && right ) {
                f=p;
                q = left;
                while(q->rchild){
                    f=q;    q=q->rchild;
                }
                p->value = q->value;
                if(f != p)  f->rchild = q->lchild;
                else f->lchild = q->lchild;
                delete q;
            }else if( !right ){
                if(f->RT(e)) f->rchild=right;
                else f->lchild=right;
                delete p;
            }else if( !left){
                if(f->RT(e)) f->rchild=right;
                else f->lchild=right;
                delete p;
            }
            return true;
        }else{
            return false;
        }
    }
private:

    void dispaly(BSTNode *p){
        if(p){
            dispaly(p->lchild);
            p->display();
            dispaly(p->rchild);
        }
    }

};

int main()
{
    BSTree bst;
    int a[]= {45, 24, 53, 45, 12, 24, 90};
    for(auto i : a)
        bst.insert_BST(i);

    bst.dispaly();
    bst.delete_BST(53);
    bst.dispaly();
    return 0;
}
