#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define _for(i,a,b) for(int i=a; i<b; i++)
#define MY_MIN  99999999
#define MY_MAX  -99999999
const int N=1e5+5;
int n,m, h;
//int a[N], cnt=0, vis[N];
int main()
{
    freopen("1.txt", "r", stdin);
    int n;
    char a,b;
    string str;
    //"dong","nan","xi","bei",¡°zhong¡±,"fa","bai"
    int mj[3][10]={0}, word[7]={0}, suit[3]={0};
    set<string> words;
    map<char,int> suit2id;
    suit2id['s']=0;
    suit2id['p']=1;
    suit2id['w']=2;

    _for(i,0,14){
        cin >> str;
        if(isdigit(str[0])){
            b=str[1];
            ++suit[suit2id[b]];
            ++mj[suit2id[b]][str[0]-'0'];
        }else{
            words.insert(str);
        }
    }
    int sum=0;
    _for(i,0,3){
        if(suit[i]==0){
            ++sum;
        }
    }

    bool jlbd=false, ssy=false;//I dont know!
    if(sum==2){//maybe jiulianbaodeng!
        jlbd=1;
        int type =suit2id[b];
        _for(i,2,9){
            if(mj[type][i]==0){
                jlbd=0;
            }
        }
        if(mj[type][1]<3 ||  mj[type][9]<3){
            jlbd=0;
        }
    }else if(sum==0){//maybe shisanyao!
        ssy=1;
        if(words.size() != 7){
            ssy=0;
        }
        _for(i,0,3){
            if(mj[i][1]==0 || mj[i][9]==0){
                ssy=0;
            }
        }
    }

    if(ssy){
        printf("shisanyao!\n");
    }else if(jlbd){
        printf("jiulianbaodeng!\n");    }else{
        printf("I dont know!\n");
    }




    return 0;
}

