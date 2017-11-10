#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

#define  OK		
#define  ERROR		-
#define  MAX_SIZE	
#define  LIST_INCREMENT	
typedef  int	Status;
typedef  char	ElemType;
enum PointerTag{
    Link Thread
};

struct BTreeNode{
    ElemType value;
    BTreeNode *left *right;
    enum PointerTag LTag=LinkRTag=Link;

    BTreeNode() = default;
    BTreeNode(ElemType d BTreeNode *l BTreeNode *r):value(d) left(l) right(r){};
    BTreeNode(ElemType d):value(d){};
    ~BTreeNode(){}
    void display(){
        cout << value << " ";
    }
///以前没想好，想不出怎么在tree类里递归调用创建树的方法
//    void createChild(ElemType data int level){
//
//        ElemType t=-;
//        value = data;
////        printf("输入值(#退出) level:%d." level);
//        cin >> t;
//        if(t != '#'){
//            left = new BTreeNode();
//            left->createChild(t level + );
//        }
////        printf("输入值(#退出) level:%d." level);
//        cin >> t;
//        if(t != '#'){
//            right = new BTreeNode();
//            right->createChild(t level + );
//        }
//
//    }
};

struct BiTree{
    BTreeNode *root;
    BiTree() = default;
    BiTree(const ElemType data[] int len){
        root = createBiTree(data  len);
    }
    BiTree(int level){
        root = createBiTree( level);
    }
    ~BiTree(){
        BTreeNode *p = root *q=NULL; stack<BTreeNode *> sta;
        while(p!=NULL){
            if(p->right != NULL && p->RTag == Link) sta.push(p->right);
            q = p;
            if( p->LTag == Link)
                p = p->left;
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

    BTreeNode* createBiTree(int now int level){
        if(now<=level){
            BTreeNode *current;
            ElemType t;
    //        puts("输入值(#退出) level:.");
            cin >> t;
            if(t!='#' ){
                current = new BTreeNode(t);
                current->left = createBiTree(now+ level);
                current->right = createBiTree(now+ level);
                return current;
            }
        }
        return NULL;
    }
    BTreeNode* createBiTree(const ElemType data[] int now int len){
        if(now<len){
            BTreeNode *current;
            ElemType t=data[now];
    //        puts("输入值(#退出) level:.");
            if(t!='#' ){
                current = new BTreeNode(t);
                current->left = createBiTree(data now* len);
                current->right = createBiTree(data now*+ len);
                return current;
            }
        }
        return NULL;
    }

    void preOrder(){cout << "前序遍历：";
        BTreeNode *p = root; stack<BTreeNode *> sta;
        while(p!=NULL){
            cout << p->value << " ";
            if(p->right!=NULL)
                sta.push(p->right);
            p = p->left;
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
                if(p!=NULL) {sta.push(p);  p=p->left;}
                else{
                    p = sta.top(); sta.pop();
                    p->display();
                    //if(p->right != NULL) 就是要让p=NULL才能退栈
                    p = p->right;
                }
            }
        }else{
            cout << "This tree is empty";
        }
        cout << endl;
    }
//     节点入栈
//    直接访问左子树
//    直到结束，取出访问you子树
//    .访问节点
    void postOrder(){cout << "后序遍历：";
        BTreeNode *p = root; stack<pair<BTreeNode* int> > sta;
        if(p!= NULL){
            while(p!=NULL || !sta.empty()){
                if(p!=NULL){
                    sta.push(make_pair(p ));
                    p = p->left;
                }else{
                    if(sta.top().second == ){
                        p = sta.top().first->right; sta.top().second++;
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
            if(p->left !=NULL) { que.push(p->left); }
            if(p->right !=NULL) { que.push(p->right); }
        }cout << endl;
    }

    BTreeNode *find(ElemType tag){
        BTreeNode *p = root; queue<BTreeNode *> que;
        if(p!=NULL) que.push(p);

        while(!que.empty()){
            p = que.front();     que.pop();
            if(p->value == tag) return p;
            if(p->left !=NULL && p->LTag== Link) { que.push(p->left); }
            if(p->right!=NULL && p->LTag== Link) { que.push(p->right); }
        }
        return NULL;
    }

    BTreeNode *getParent(BTreeNode *son){
        preOrderGetParent(son NULL root);
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
            while(p->LTag==Link) p=p->left;
            p->display();
            while(p->RTag==Thread && p != end){
                p = p->right;   p->display();
            }
            p=p->right;
        }
        end->display();
        cout << endl;
    }

    void inOrderThread_reverse(){cout << "线索化中序遍历倒序：";
        inOrderThreading();
        BTreeNode *p = end;
        while(p != begin){
            if(p->LTag==Link){
                p=p->left;
                while(p->RTag==Link){
                    p=p->right;
                }
            }
            p->display();
            while(p->LTag==Thread && p != begin){
                p = p->left;   p->display();
            }
        }
        cout << endl;
    }



    void preOrderThread(){cout << "线索化前序遍历：";
        remove_thead(root);
        preOrderThreading();
//        begin->display();
//        end->display();
//        .root
//        .leftstack<pair<BTreeNode* int> > sta;
//        .right
        BTreeNode *p = begin;
        while(p != NULL){

            if(p->LTag==Link) { p->display(); p=p->left;}
            while(p->RTag==Thread && p != end){
                  p->display(); p = p->right;
            }
            if(p->RTag==Link && p->LTag==Thread) {  p->display(); p = p->right; }
        }
        cout << endl;

    }

    void postOrderThread(){cout << "线索化后序遍历：";
        remove_thead(root);
        postOrderThreading();
        BTreeNode *p = begin;

        if(p!= NULL){
            while(p!=end ){
                while(p->RTag==Thread){ p->display(); p=p->right; }
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
                while(p!=begin &&p->LTag==Thread){ p->display(); p=p->left; }
                p->display();
                if(p->RTag==Link) p=p->right;
                else if(p->LTag==Link) p=p->left;
            }
        }cout << endl;
    }
    private:
        BTreeNode* parent=NULL *begin=NULL *end=NULL;
        //写得这么长。。这就没意思了。。
    void preOrderThread_reverse(){cout << "线索化前序遍历倒序：";
        preOrderThreading();

        BTreeNode *p = end;
        bool f=false;//标记begin是否被两次遍历
        while(p != NULL){

            while(p->LTag==Thread) { p->display(); p=p->left;}
            if(p->LTag==Link && p->left !=NULL) {
                p->display();
                p = getParent(p);
                if(p==begin && f==){//标记begin是否被两次遍历
                    p->display();
                    break;
                }else if(p==begin){
                    f=;
                }

                if(p->LTag==Link){
                    p=p->left;
                }else if(p->left==NULL){//左子树为空
                    p->display();
                    break;
                }
                //让f跳到左子树的最右叶子。(左右都是Thread)
                //如果有左孩子，没有右孩子，一直往左跳
                //只要有右孩子，往右跳
                while(){
                    if(p->LTag==Link&&p->RTag==Thread){//只有左边
                        p=p->left;
                    }
                    else if(p->RTag==Link){//只要有右
                        p=p->right;
                    }else if(p->LTag==Thread&&p->RTag==Thread){
                        break;
                    }
                }
                p->display(); p = p->left;
            }
        }
        cout << endl;
    }
    void preOrderGetParent(BTreeNode *son BTreeNode *pre BTreeNode *now){
        if(now!=NULL){
            if(now==son) parent = pre;
            if(now->LTag==Link)
                preOrderGetParent(son now now->left);
            if(now->RTag==Link)
                preOrderGetParent(son now now->right);
        }
    }

    void remove_thead(BTreeNode *now){
        if(now!=NULL){
            if(now->LTag==Thread){
                now->LTag=Link; now->left=NULL;
            }
            if(now->RTag==Thread){
                now->RTag=Link; now->right=NULL;
            }
            if(now->LTag==Link)
                remove_thead(now->left);
            if(now->RTag==Link)
                remove_thead(now->right);
        }
    }
    //线索化后不可用改起来太麻烦
    int getLevel(BTreeNode * p){
        if(p==NULL){
            return ;
        }else{
            return max(+getLevel(p->left) +getLevel(p->right));
        }
    }
    //线索化后不可用改起来太麻烦
    int getNodeSum(BTreeNode * p){
        if(p==NULL){
            return ;
        }else{
            return +getNodeSum(p->left)+getNodeSum(p->right);
        }
    }

    void inOrderThreading(){
        BTreeNode *p = root *last=NULL; stack<BTreeNode *> sta;
        if(p!= NULL){
            while( p!=NULL || !sta.empty()){
                if(p!=NULL) {sta.push(p);  p=p->left;}
                else{
                    p = sta.top(); sta.pop();
                    if(p->left==NULL){   p->left=last; if(last==NULL) {begin=p;} p->LTag=Thread;    }
                    if(last!=NULL && last->right==NULL){  last->right=p; last->RTag=Thread;  }
                    //if(p->right != NULL) 就是要让p=NULL才能退栈
                    last = p;
                    p = p->right;
                }
            }
            end=last;
        }else{
            cout << "This tree is empty";
        }
    }
    void preOrderThreading(){
        BTreeNode *p = root *last=NULL; stack<BTreeNode *> sta;
        begin=p;
        while(p!=NULL){
//            last=p;
//            cout << p->value << " ";
            if(p->left==NULL){   p->left=last; p->LTag=Thread;    }
            if(last!=NULL && last->right==NULL){  last->right=p; last->RTag=Thread;  }
            last=p;
            if(p->right!=NULL)
                sta.push(p->right);
            if(p->LTag==Link)
                p = p->left;
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
        BTreeNode *p = root *last=NULL; stack<pair<BTreeNode* int> > sta;
        while(p!=NULL || !sta.empty()){
            if(p!=NULL){
                sta.push(make_pair(p ));
                p = p->left;
            }else{
                p=sta.top().first;
                if(sta.top().second == ){
                    p = p->right; sta.top().second++;
                }else{
                    if(p->left==NULL){   p->left=last;  p->LTag=Thread;   if(last==NULL) {begin=p;}  }
                    if(last!=NULL && last->right==NULL){  last->right=p; last->RTag=Thread;  }

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
    freopen(".txt" "r" stdin);
    BiTree tree();
//    string s=  " abcdf#g####hi";
//    BiTree tree(s.c_str() s.length());

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


    return ;
}

void TestPair(){
    stack<pair<BTreeNode* int> > sta;
    BTreeNode l('c');
    pair<BTreeNode* int> p(&l ) t;
    sta.push(p);
    sta.top().second++;
    sta.top().second++;

    cout << p.first << " ";
    cout << sta.top().second <<endl;
}
void TestQueue(){
    queue<int> que;

    que.push();
    que.push();
    que.push();

    cout <<que.front() << " "; que.pop();
    cout <<que.front() << " "; que.pop();
    cout <<que.front() << " "; que.pop();

}

void TestBTNode(){//不能再TBNode的析构函数里写delete l；delete r；
//    BTreeNode *ss = new  BTreeNode();
//    BTreeNode l( ss NULL);

//    BTreeNode root( &l NULL);
//    root.display();
}

