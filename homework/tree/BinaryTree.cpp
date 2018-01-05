#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

#define  OK		1
#define  ERROR		-1
#define  MAX_SIZE	100
#define  LIST_INCREMENT	10
typedef  int	Status;
typedef  char	ElemType;
enum PointerTag{
    Link, Thread
};

struct BTreeNode{
    ElemType value;
    BTreeNode *lchild, *rchild;
    enum PointerTag LTag=Link,RTag=Link;

    BTreeNode() = default;
    BTreeNode(ElemType d, BTreeNode *l, BTreeNode *r):value(d), lchild(l), rchild(r){};
    BTreeNode(ElemType d):value(d){};
    ~BTreeNode(){}
    void display(){
        cout << value << " ";
    }
///以前没想好，想不出怎么在tree类里递归调用创建树的方法
//    void createChild(ElemType data, int level){
//
//        ElemType t=-1;
//        value = data;
////        printf("输入值(#退出), level:%d.", level);
//        cin >> t;
//        if(t != '#'){
//            lchild = new BTreeNode();
//            lchild->createChild(t, level + 1);
//        }
////        printf("输入值(#退出), level:%d.", level);
//        cin >> t;
//        if(t != '#'){
//            rchild = new BTreeNode();
//            rchild->createChild(t, level + 1);
//        }
//
//    }
};

struct BiTree{
    BTreeNode *root;
    BiTree() = default;
    BiTree(const ElemType data[], int len){
        root = createBiTree(data, 1, len);
    }
    BiTree(int level){
        root = createBiTree(1, level);
    }
    ~BiTree(){
        BTreeNode *p = root, *q=NULL; stack<BTreeNode *> sta;
        while(p!=NULL){
            if(p->rchild != NULL && p->RTag == Link) sta.push(p->rchild);
            q = p;
            if( p->LTag == Link)
                p = p->lchild;
            else
                p = NULL;
            cout << "刪除了" << q->value << endl;
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

    BTreeNode* createBiTree(int now, int level){
        if(now<=level){
            BTreeNode *current;
            ElemType t;
    //        puts("输入值(#退出), level:1.");
            cin >> t;
            if(t!='#' ){
                current = new BTreeNode(t);
                current->lchild = createBiTree(now+1, level);
                current->rchild = createBiTree(now+1, level);
                return current;
            }
        }
        return NULL;
    }
    BTreeNode* createBiTree(const ElemType data[], int now, int len){
        if(now<len){
            BTreeNode *current;
            ElemType t=data[now];
    //        puts("输入值(#退出), level:1.");
            if(t!='#' ){
                current = new BTreeNode(t);
                current->lchild = createBiTree(data, now*2, len);
                current->rchild = createBiTree(data, now*2+1, len);
                return current;
            }
        }
        return NULL;
    }

    void preOrder(){cout << "前序遍历：";
        BTreeNode *p = root; stack<BTreeNode *> sta;
        while(p!=NULL){
            cout << p->value << " ";
            if(p->rchild!=NULL)
                sta.push(p->rchild);
            p = p->lchild;
            if(p==NULL ){
                if(sta.empty()){ break; }
                else{
                    p = sta.top();
                    sta.pop();
                }
            }
        }cout << endl;
    }

    void inOrder(){cout << "中序遍历：";
        BTreeNode *p = root; stack<BTreeNode *> sta;
        if(p!= NULL){
            while( p!=NULL || !sta.empty()){
                if(p!=NULL) {sta.push(p);  p=p->lchild;}
                else{
                    p = sta.top(); sta.pop();
                    p->display();
                    //if(p->rchild != NULL) 就是要让p=NULL,才能退栈
                    p = p->rchild;
                }
            }
        }else{
            cout << "This tree is empty";
        }
        cout << endl;
    }
//     节点入栈
//    直接访问左子树
//    直到2结束，取出访问you子树
//    2.访问节点
    void postOrder(){cout << "后序遍历：";
        BTreeNode *p = root; stack<pair<BTreeNode*, int> > sta;
        if(p!= NULL){
            while(p!=NULL || !sta.empty()){
                if(p!=NULL){
                    sta.push(make_pair(p, 0));
                    p = p->lchild;
                }else{
                    if(sta.top().second == 0){
                        p = sta.top().first->rchild; sta.top().second++;
                    }else{
                        sta.top().first->display();
                        sta.pop();
                        p = NULL;
                    }
                }
            }
        }else{
            cout << "This tree is empty";
        }
        cout << endl;
    }

    void levelOrder(){cout << "层序遍历：";
        BTreeNode *p = root; queue<BTreeNode *> que;
        if(p!=NULL) que.push(p);
        else cout << "This tree is empty";
        while(!que.empty()){
            p = que.front();     que.pop();
            p->display();
            if(p->lchild !=NULL) { que.push(p->lchild); }
            if(p->rchild !=NULL) { que.push(p->rchild); }
        }cout << endl;
    }

    BTreeNode *find(ElemType tag){
        BTreeNode *p = root; queue<BTreeNode *> que;
        if(p!=NULL) que.push(p);

        while(!que.empty()){
            p = que.front();     que.pop();
            if(p->value == tag) return p;
            if(p->lchild !=NULL && p->LTag== Link) { que.push(p->lchild); }
            if(p->rchild!=NULL && p->LTag== Link) { que.push(p->rchild); }
        }
        return NULL;
    }

    BTreeNode *getParent(BTreeNode *son){
        preOrderGetParent(son, NULL, root);
        return parent;
    }

    int getLevel(){
        return getLevel(root);
    }

    int getNodeSum(){
        return getNodeSum(root);
    }


    void inOrderThread(){cout << "线索化中序遍历：";
        inOrderThreading();
        BTreeNode *p = begin;
        while(p != end){
            while(p->LTag==Link) p=p->lchild;
            p->display();
            while(p->RTag==Thread && p != end){
                p = p->rchild;   p->display();
            }
            p=p->rchild;
        }
        end->display();
        cout << endl;
    }

    void inOrderThread_reverse(){cout << "线索化中序遍历倒序：";
        inOrderThreading();
        BTreeNode *p = end;
        while(p != begin){
            if(p->LTag==Link){
                p=p->lchild;
                while(p->RTag==Link){
                    p=p->rchild;
                }
            }
            p->display();
            while(p->LTag==Thread && p != begin){
                p = p->lchild;   p->display();
            }
        }
        cout << endl;
    }



    void preOrderThread(){cout << "线索化前序遍历：";
        remove_thead(root);
        preOrderThreading();
//        begin->display();
//        end->display();
//        1.root
//        2.leftstack<pair<BTreeNode*, int> > sta;
//        3.rchild
        BTreeNode *p = begin;
        while(p != NULL){

            if(p->LTag==Link) { p->display(); p=p->lchild;}
            while(p->RTag==Thread && p != end){
                  p->display(); p = p->rchild;
            }
            if(p->RTag==Link && p->LTag==Thread) {  p->display(); p = p->rchild; }
        }
        cout << endl;

    }

    void postOrderThread(){cout << "线索化后序遍历：";
        remove_thead(root);
        postOrderThreading();
        BTreeNode *p = begin;

        if(p!= NULL){
            while(p!=end ){
                while(p->RTag==Thread){ p->display(); p=p->rchild; }
                p->display();
                p=getParent(p);

            }end->display();
        }else{
            cout << "This tree is empty";
        }
        cout << endl;

    }
    void postOrderThread_reverse(){cout << "线索化后序遍历倒序：";
        remove_thead(root);
        postOrderThreading();
        BTreeNode *p = end;

        if(p!= NULL){
            while(p!=begin ){
                while(p!=begin &&p->LTag==Thread){ p->display(); p=p->lchild; }
                p->display();
                if(p->RTag==Link) p=p->rchild;
                else if(p->LTag==Link) p=p->lchild;
            }
        }cout << endl;
    }
    private:
        BTreeNode* parent=NULL, *begin=NULL, *end=NULL;
        //写得这么长。。这就没意思了。。
    void preOrderThread_reverse(){cout << "线索化前序遍历倒序：";
        preOrderThreading();

        BTreeNode *p = end;
        bool f=false;//标记begin是否被两次遍历
        while(p != NULL){

            while(p->LTag==Thread) { p->display(); p=p->lchild;}
            if(p->LTag==Link && p->lchild !=NULL) {
                p->display();
                p = getParent(p);
                if(p==begin && f==1){//标记begin是否被两次遍历
                    p->display();
                    break;
                }else if(p==begin){
                    f=1;
                }

                if(p->LTag==Link){
                    p=p->lchild;
                }else if(p->lchild==NULL){//左子树为空
                    p->display();
                    break;
                }
                //让f跳到左子树的最右叶子。(左右都是Thread)
                //如果有左孩子，没有右孩子，一直往左跳
                //只要有右孩子，往右跳
                while(1){
                    if(p->LTag==Link&&p->RTag==Thread){//只有左边
                        p=p->lchild;
                    }
                    else if(p->RTag==Link){//只要有右,
                        p=p->rchild;
                    }else if(p->LTag==Thread&&p->RTag==Thread){
                        break;
                    }
                }
                p->display(); p = p->lchild;
            }
        }
        cout << endl;
    }
    void preOrderGetParent(BTreeNode *son, BTreeNode *pre, BTreeNode *now){
        if(now!=NULL){
            if(now==son) parent = pre;
            if(now->LTag==Link)
                preOrderGetParent(son, now, now->lchild);
            if(now->RTag==Link)
                preOrderGetParent(son, now, now->rchild);
        }
    }

    void remove_thead(BTreeNode *now){
        if(now!=NULL){
            if(now->LTag==Thread){
                now->LTag=Link; now->lchild=NULL;
            }
            if(now->RTag==Thread){
                now->RTag=Link; now->rchild=NULL;
            }
            if(now->LTag==Link)
                remove_thead(now->lchild);
            if(now->RTag==Link)
                remove_thead(now->rchild);
        }
    }
    //线索化后不可用,改起来太麻烦
    int getLevel(BTreeNode * p){
        if(p==NULL){
            return 0;
        }else{
            return max(1+getLevel(p->lchild), 1+getLevel(p->rchild));
        }
    }
    //线索化后不可用,改起来太麻烦
    int getNodeSum(BTreeNode * p){
        if(p==NULL){
            return 0;
        }else{
            return 1+getNodeSum(p->lchild)+getNodeSum(p->rchild);
        }
    }

    void inOrderThreading(){
        BTreeNode *p = root, *last=NULL; stack<BTreeNode *> sta;
        if(p!= NULL){
            while( p!=NULL || !sta.empty()){
                if(p!=NULL) {sta.push(p);  p=p->lchild;}
                else{
                    p = sta.top(); sta.pop();
                    if(p->lchild==NULL){   p->lchild=last; if(last==NULL) {begin=p;} p->LTag=Thread;    }
                    if(last!=NULL && last->rchild==NULL){  last->rchild=p; last->RTag=Thread;  }
                    //if(p->rchild != NULL) 就是要让p=NULL,才能退栈
                    last = p;
                    p = p->rchild;
                }
            }
            end=last;
        }else{
            cout << "This tree is empty";
        }
    }
    void preOrderThreading(){
        BTreeNode *p = root, *last=NULL; stack<BTreeNode *> sta;
        begin=p;
        while(p!=NULL){
//            last=p;
//            cout << p->value << " ";
            if(p->lchild==NULL){   p->lchild=last; p->LTag=Thread;    }
            if(last!=NULL && last->rchild==NULL){  last->rchild=p; last->RTag=Thread;  }
            last=p;
            if(p->rchild!=NULL)
                sta.push(p->rchild);
            if(p->LTag==Link)
                p = p->lchild;
            else
                p = NULL;
            if(p==NULL ){
                if(sta.empty()){ break; }
                else{
                    p = sta.top();
                    sta.pop();
                }
            }
        }
        end=last;
    }

    void postOrderThreading(){
        BTreeNode *p = root, *last=NULL; stack<pair<BTreeNode*, int> > sta;
        while(p!=NULL || !sta.empty()){
            if(p!=NULL){
                sta.push(make_pair(p, 0));
                p = p->lchild;
            }else{
                p=sta.top().first;
                if(sta.top().second == 0){
                    p = p->rchild; sta.top().second++;
                }else{
                    if(p->lchild==NULL){   p->lchild=last;  p->LTag=Thread;   if(last==NULL) {begin=p;}  }
                    if(last!=NULL && last->rchild==NULL){  last->rchild=p; last->RTag=Thread;  }

                    last = p;
                    sta.pop();
                    p = NULL;
                }
            }
        }
        end=root;
    }



};

void TestQueue();
int main()
{
    freopen("1.txt", "r", stdin);
    BiTree tree(4);
//    string s=  " abcd62f#g####hi";
//    BiTree tree(s.c_str(), s.length());

//    switch(){实在懒得写界面了。。。。
//
//    }

    tree.preOrder();
    tree.inOrder();
    tree.postOrder();
    tree.levelOrder();

    int level = tree.getLevel();
    int sum = tree.getNodeSum();
    cout << level << " " << sum << endl;

    BTreeNode *f = tree.find('f');
    if(f!=NULL){
        BTreeNode *p = tree.getParent(f);
        f->display(); cout << endl;
        p->display(); cout << endl;
    }
    tree.inOrderThread_reverse();
    tree.preOrderThread();
    tree.postOrderThread_reverse();


    return 0;
}

void TestPair(){
    stack<pair<BTreeNode*, int> > sta;
    BTreeNode l('c');
    pair<BTreeNode*, int> p(&l, 0), t;
    sta.push(p);
    sta.top().second++;
    sta.top().second++;

    cout << p.first << " ";
    cout << sta.top().second <<endl;
}
void TestQueue(){
    queue<int> que;

    que.push(2);
    que.push(22);
    que.push(222);

    cout <<que.front() << " "; que.pop();
    cout <<que.front() << " "; que.pop();
    cout <<que.front() << " "; que.pop();

}

void TestBTNode(){//不能再TBNode的析构函数里写delete l；delete r；
//    BTreeNode *ss = new  BTreeNode(666);
//    BTreeNode l(2, ss, NULL);

//    BTreeNode root(3, &l, NULL);
//    root.display();
}

