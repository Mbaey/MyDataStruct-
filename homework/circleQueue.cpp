#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <queue>

#include "LinkedList.cpp"
using namespace std;
#define  OK		1
#define  ERROR		-1
#define MAX_SIZE 3
template <class T>
struct MyQueue{
    T data[MAX_SIZE];
    int front, rear, len;


    int push_back(T d){
        if(len != MAX_SIZE){
            ++len;
            data[rear] = d;
            rear = (rear + 1)  % MAX_SIZE;
            return OK;
        }else{
            return ERROR;
        }
    }
    int empty(){    return len == 0 ? 1 : 0;    }
    int size(){    return len;  }

    T get_front(){
        if(!empty()){
            return data[front];
        }else{
            return ERROR;
        }
    }

    T pop_front(){
        if(!empty()){
            int res = data[front];
            front = (front + 1)  % MAX_SIZE;
            --len;
            return res;
        }else{
            return ERROR;
        }
    }

    void display(){
        int temp = front;
        for(int i=0; i<len; i++){
            if(i != 0) cout << " ";
            cout << data[temp];
            temp = (temp + 1 ) % MAX_SIZE;
        }putchar('\n');
    }
};

int stoi(string s){    stringstream ss(s);    int res;    ss >> res;    return res;}
queue<int> q;
MyQueue<int> myq;
int main(){
    myq.push_back(1);
    myq.push_back(10);
    myq.push_back(100);
    myq.display();
    cout << myq.pop_front() << endl;
    myq.push_back(666);
    myq.display();

    return 0;
}
