#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
//#include "LinkedList.h"
using namespace std;

#define  OK		1
#define  ERROR		-1
//多项式加法 乘法就是两个for循环。
struct Polynomial{
    float coef=0; //系数
    int expn=0; //指数
    Polynomial()=default;
    Polynomial(float c, int e) : coef(c), expn(e){};
    ~Polynomial(){};
    void negate(){ coef*=-1;}

};
ostream &operator<<(ostream &os, const Polynomial p){ os << p.coef <<"x^" << p.expn; return os;}
Polynomial operator+(const Polynomial p1, const Polynomial p2) { Polynomial sum(p1.coef+p2.coef, p1.expn); return sum;}//指数相同时+ - 才有效
Polynomial operator-(const Polynomial p1, const Polynomial p2) { Polynomial sum(p1.coef-p2.coef, p1.expn); return sum;}
bool operator<(const Polynomial p1, const Polynomial p2) { return p1.expn < p2.expn;}
bool operator>(const Polynomial p1, const Polynomial p2) { return p1.expn > p2.expn;}
bool operator==(const Polynomial p1, const Polynomial p2) { return p1.expn == p2.expn;}
template <class T>
struct Node{
    public:
        T data;
        Node* prev=NULL;
        Node* next=NULL;

    Node<T>()=default;
    Node<T>(T d): data(d){};
    Node<T>(T d, Node* p, Node* n): data(d), prev(p), next(n){};
//    Node(T d);
    ~Node();
};

template <class T> Node<T>::~Node(){
//    cout << "data:"<< data <<"   next:"<< next << "xi gou han shu" << endl;
}

template <class T>
class LinkedList
{
    public:
        Node<T> *head=NULL, *tail=NULL;
        int len=0;
    public:
        LinkedList();
        ~LinkedList();

        void push_back(T d);
        void push_head(T d);
        void display();
        T at(int index);
        int erase(int index);
        int update(int index, T d);
        int search(T d);//1 ok -1 not found
        int insert(int index, T d);
        void AddPolyn(const LinkedList<T> &p2,LinkedList<T> &res){
            int sumLen = len + p2.len;


            Node<T> *p= head->next;
            Node<T> *q = p2.head->next;
            for(int i=0; i<sumLen; i++){
                if(p==NULL&&q==NULL){
                    break;
                }else if(p==NULL){
                    res.push_back(q->data);
                    q= q->next;
                }else if(q==NULL){
                    res.push_back(p->data);
                    p= p->next;
                }else{
                    if(p->data < q->data){//p指数小
                        res.push_back(p->data);
                        p= p->next;
                    }else if(p->data > q->data){
                        res.push_back(q->data);
                        q= q->next;
                    }else{
                        Polynomial data  = p->data + q->data;
                        if(data.coef != 0)
                            res.push_back(data);
                        q = q->next;
                        p = p->next;
                    }
                }

            }

        }
        int negatePolyn(){
            for(Node<T> *p = head->next; p != NULL ; p = p->next){
                p->data.negate();
            }
            return OK;
        }

};

template <class T>  LinkedList<T>::LinkedList(){
    head = new Node<T>();
    tail = new Node<T>();
    head->next = tail;
    tail->prev = head;
    len=0;
}

template <class T>  LinkedList<T>::~LinkedList(){
    Node<T> *p=head, *pre=NULL;
    while(p!=NULL){
        pre = p;
        p = p->next;
        delete pre;
    }
//如果没写迭代工具的话就只能这样实现了
}

template <class T> void LinkedList<T>::push_back(T d){

    len++;
    if(len==1){
        tail->data = d;
    }else{
        Node<T> *trueTail = new Node<T>(d, tail, NULL);
        tail->next = trueTail;
        tail = trueTail;
    }
}

template <class T> void LinkedList<T>::push_head(T d){
    len++;
    if(len==1){
        tail->data = d;
    }else{
        Node<T> *trueHead = new Node<T>(d, head, head->next);
        head->next= trueHead;
        (*trueHead->next).prev = trueHead;
        return;
    }
}

template <class T> void LinkedList<T>::display(){

    for(Node<T> *p = head->next; p != NULL && p->next != NULL; p = p->next){
        cout << p->data << " + ";
    }
    if(len != 0)
        cout << tail->data << endl;
}
template <class T> T LinkedList<T>::at(int index){
    if(index <= len - 1){
        Node<T> *p = head->next;
        for(int i=0; i<index ;i++){
            p = p->next;
        }
        return p->data;
    }
    return ERROR;
}
template <class T> int LinkedList<T>::update(int index, T d){
    if(index <= len - 1){
        Node<T> *p = head->next;
        for(int i=0; i<index ;i++){
            p = p->next;
        }
        p->data = d;
        return OK;
    }
    return ERROR;
}
template <class T> int LinkedList<T>::erase(int index){
    if(index < len - 1){
        Node<T> *p = head->next;

        for(int i=0; i<index ;i++){
            p = p->next;
        }
        (*p->prev).next = p->next;
        (*p->next).prev = (p->prev);

        len--;
        delete p;


        return OK;
    }else if(index == len - 1){
        (*tail->prev).next = NULL;
        tail = tail->prev;

        len--;
        delete tail->next;

        return OK;
    }
    return ERROR;
}

template <class T> int LinkedList<T>::insert(int index, T d){
    if(index < len - 1){
        Node<T> *p = head->next;

        for(int i=0; i<index-1 ;i++){
            p = p->next;
        }
        Node<T> *n = new Node<T>(d, p, p->next);
        (*p->next).prev = n;
        p->next = n;
        len++;
        return OK;
    }
    return ERROR;

}
template <class T> int LinkedList<T>::search(T d){
    Node<T> *p = head->next;

    for(int i=0; i<len ;i++){
        if(p->data == d){
            return i;
        }
        p = p->next;
    }
    return ERROR;
}
int main(){
    LinkedList<Polynomial> myPoly1, myPoly2;
    Polynomial a(1,1); Polynomial b(2,2);
    myPoly1.push_back(a); myPoly1.push_back(b);
    Polynomial c(3,2); Polynomial d(5,5);
    myPoly2.push_back(c);
    myPoly2.push_back(d);
    bool f (a<b);
    cout << f << endl;
    myPoly1.display();
    myPoly2.negatePolyn();
    myPoly2.display();
    LinkedList<Polynomial> myPoly3 ;
    myPoly1.AddPolyn(myPoly2, myPoly3);

    myPoly1.display();
    myPoly2.display();
    myPoly3.display();

    cout << "Hello world" << endl;
    return 0;
}

