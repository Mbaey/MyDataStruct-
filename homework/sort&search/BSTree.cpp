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
    int bf=0; //平衡因子
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
    bool RT(NodeType b){ // a 比 b 小 往右走
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
//            cout << "刪除了" << q->value << endl;
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
    /*如果寻找到被删的节点

    1.该节点有左右孩子  -》 放到左子树 的 最右端
    2.该节点有左孩子    -》 把左孩子 赋值 给他爸
    3.该节点有右孩子    -》 把右孩子 赋值 给他爸
    4.该节点沒有左右孩子 -》直接删
    */
	/*
	http://blog.csdn.net/sysu_arui/article/details/7865864
	3、删除
	在二叉查找树中删除一个给定的结点p有三种情况
	(1)  结点p无左右子树，则直接删除该结点，修改父节点相应指针
	(2)  结点p有左子树（右子树），则把p的左子树（右子树）接到p的父节点上
	(3)  左右子树同时存在，则有三种处理方式
	a.      找到结点p的中序直接前驱结点s，把结点s的数据转移到结点p，然后删除结点s，由于结点s为p的左子树中最右的结点，因而s无右子树，删除结点s可以归结到情况(2)。严蔚敏数据结构P230-231就是该处理方式。
	b.     找到结点p的中序直接后继结点s，把结点s的数据转移到结点p，然后删除结点s，由于结点s为p的右子树总最左的结点，因而s无左子树，删除结点s可以归结到情况(2)。算法导论第2版P156-157该是该处理方式。
	c.      找到p的中序直接前驱s，将p的左子树接到父节点上，将p的右子树接到s的右子树上，然后删除结点p。
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
