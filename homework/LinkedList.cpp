#include <iostream>
#include <cstdlib>
#include <list>
#include <cstdio>
//#include "LinkedList.h"
using namespace std;

#define ERROR -1
#define OK 1


template <class T>
struct Node{
    public:
        T data=0;
        Node* next=NULL;
        Node* prev=NULL;

    Node<T>()=default;
    Node<T>(T d): data(d){};
    Node<T>(T d, Node* p, Node* n): data(d), prev(p), next(n){};
//    Node(T d);
    ~Node();
};

template <class T> Node<T>::~Node(){
    cout << "data:"<< data <<"   next:"<< next << "xi gou han shu" << endl;
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
        cout << p->data << " ";
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

int main()
{

    LinkedList<int> myList;

    myList.push_back(10);
    myList.push_back(100);
    myList.push_back(1000);
    myList.push_head(88);


    myList.display();
    myList.update(2, 666);
    cout << myList.at(3)<< endl;
    myList.erase(1);
    cout << myList.len<< endl;
    myList.display();
    return 0;
}
