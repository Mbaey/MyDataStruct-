#include <iostream>
#include "LinkedList.cpp"

using namespace std;

struct String{
    LinkedList<char> str;
    String()=default;
    String(string s){       this->assign(s);    }

    int length();
    int clear();
    void display();
    void assign(string s);
    int concat(string s);//拼接
    int cmp(String &s);
    int subStr(String &s, int pos, int len);
    int update(int index, char c){
        str.update(index, c);
    }
};
int String::length(){
   return str.len;
}
int String::clear(){
   return str.clear();
}
void String::display(){
   return str.display();
}

void String::assign(string s){
    for(auto i : s){
        str.push_back(i);
    }
}
int String::concat(string s){
    for(auto i : s){
        str.push_back(i);
    }
    return OK;
}
int String::cmp(String &s){
    int len = str.len > s.str.len ? str.len : s.str.len;
    for(int i=0; i<len; i++){

        if(i> str.len){
            return -1;
        }else if(i>s.length()){
            return 1;
        }
        if(str.at(i) < s.str.at(i)){
            return -1;
        }else if(str.at(i) > s.str.at(i)){
            return 1;
        }
    }
    return 0;
}
int String::subStr(String &s, int pos, int len){//[pos, len)

    int n = len + pos;
    if(n >= str.len){
        return ERROR;
    }
    s.clear();
    for(int i=pos; i<n; i++){
        s.str.push_back(str.at(i));
    }

    return OK;
}
void sayBigSmall(int i){
    if(i>0){
        cout << "前比后大"<< endl;    }else if(i<0){
        cout << "前比后小"<< endl;
    }else{
        cout << "前后一样大"<< endl;
    }
}
int main()
{
    String l("I'm Li "), str("I'm li ");
    sayBigSmall(str.cmp(l));
    str.update(4, 'L');

    sayBigSmall(str.cmp(l));

    l.concat("Hello world");
    l.subStr(str, 0, 10);
    str.display();
    l.display();
    sayBigSmall(str.cmp(l));
    return 0;
}
