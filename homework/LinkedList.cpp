#include <iostream>
#include <cstdlib>
#include <list>
#include <cstdio>
//#include "LinkedList.h"
using namespace std;

#define ERROR -1
#define SUCCESS 1


template <class T>
struct Node{
    public:
        T data=0;
        Node* next=NULL;

    Node<T>()=default;
    Node<T>(T d): data(d){};
//    Node(T d);
    ~Node();
};

template <class T> Node<T>::~Node(){
    cout << "data:"<< data <<"   next:"<< next << "xi gou han shu" << endl;
    free(next);
}

template <class T>
class LinkedList
{
    public:
        Node<T> head, *tail=NULL;
        int len=0;
    public:
        LinkedList();
        ~LinkedList();

        void push_back(T d);
        void push_head(T d);
        void display();
        T searchByIndex(int index);
        int deleteByIndex(int index);

};

template <class T>  LinkedList<T>::LinkedList(){}

template <class T>  LinkedList<T>::~LinkedList(){ delete tail;}

template <class T> void LinkedList<T>::push_back(T d){
    Node<T> *trueTail = new Node<T>(d);
    len++;
    if(len==1){
        head.next = trueTail;
        tail = trueTail;
    }else{
        tail->next = trueTail;
        tail = trueTail;
    }
}

template <class T> void LinkedList<T>::push_head(T d){
    Node<T> *trueHead = new Node<T>(d);
    len++;
    if(len==1){
        tail = trueHead;
    }else{
        trueHead->next=head.next;
        head.next= trueHead;
    }
}

template <class T> void LinkedList<T>::display(){

    for(Node<T> *p = head.next; p->next != NULL; p = p->next){
        cout << p->data << " ";
    }
    cout << tail->data << endl;
}
template <class T> T LinkedList<T>::searchByIndex(int index){
    if(index <= len - 1){
        Node<T> *p = head.next;
        for(int i=0; i<index ;i++){
            p = p->next;
        }
        return p->data;
    }
    return ERROR;
}
template <class T> int LinkedList<T>::deleteByIndex(int index){
    if(index <= len - 1){
        Node<T> *p = head.next;
        Node<T> *pre = head.next;
        for(int i=0; i<index ;i++){
            pre = p;
            p = p->next;
        }
        pre->next = p->next;
//        delete p;
        len--;
        if(index == len-1)
            tail = p->next;
        return SUCCESS;
    }
    return ERROR;
}

int main()
{

    LinkedList<int> myList;

    myList.push_back(10);
    myList.push_back(100);
    myList.push_back(1000);
    myList.push_head(0);


    myList.display();
    cout << myList.searchByIndex(2)<< endl;
    myList.deleteByIndex(2);
    cout << myList.len<< endl;
    myList.display();
    return 0;
}
