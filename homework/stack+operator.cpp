#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

#include "LinkedList.cpp"
using namespace std;

template <class T>
struct MyStack{
    LinkedList<T> st;

    MyStack() = default;
    ~MyStack(){ };

    void clear(){        st.clear();    }
    void push(T d){        st.push_back(d);    }
    void pop(){        st.erase(st.len - 1);    }
    T getPop(){      return  st.at(st.len - 1 );    }
    void display() { st.display();}
    int length() { return st.len;}
    bool empty() { return st.len == 0 ? 1 : 0;}

};
void Operator(MyStack<int> &num, MyStack<char> &op){
    char op1 = op.getPop(); op.pop();     //ȡ��������ջ��Ԫ��
    int num1 = num.getPop(); num.pop();    //ȡ��������ջ��Ԫ��
    int num2 = num.getPop(); num.pop();   //ȡ��������ջ��Ԫ��
    if(op1 == '+'){                    //���������Ϊ+����ִ����������������Ͳ������������ѹ�������ջ��
        num.push(num2 + num1);
    }else if(op1 == '-'){
        num.push(num2 - num1);
    }else if(op1 == '*'){
        num.push(num2 * num1);
    }else if(op1 == '/'){
        num.push(num2 / num1);
    }
}

int main(){
    MyStack<int> num;
    MyStack<char> op;

//    op.push('+');
//    op.pop();
//    op.push('+');
//    cout <<  op.getPop();
    string s("1+2*(1+2)");
    char top=0;
    for(auto c : s){
        if(isdigit(c)){ num.push(c-'0');   }
        else if(c=='+' || c=='-'){

            while(!op.empty() && (op.getPop()=='+' || op.getPop()=='-' || op.getPop()=='*' || op.getPop()=='/') ){//  */+- �����ȼ����� + - ��
                Operator(num,op);
            }
            op.push(c);
        }
        else if(c=='*' || c=='/'){

            while(!op.empty() && (op.getPop()=='*' || op.getPop()=='/') ){//  */ �����ȼ����� / * ��
                Operator(num,op);
            }
            op.push(c);
        }
        else if(c=='('){            op.push(c);        }
        else if(c==')'){
            while(!op.empty() && (op.getPop() !='(') ){//  ���� ��  ֮ǰһֱ����
                Operator(num,op);
            }
            op.pop();
        }

    }
    while(!op.empty()){//û��()��
        Operator(num,op);
        num.display();
    }
	//��ʱջ��Ԫ�� Ϊres
	cout << num.getPop() << endl;

    return 0;
}

