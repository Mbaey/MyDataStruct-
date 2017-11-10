#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

#define  OK		1
#define  ERROR		-1
#define  MAX_SIZE	100
#define  MAX_VALUE	131072
#define  LIST_INCREMENT	10
typedef  int	Status;
typedef  char	ElemType;
//map={"x" -> 19, "z" -> 137, "y" -> 248, "q" -> 412, "k" -> 577,
// "j" -> 711, "v" -> 1206, "n" -> 1698, "o" -> 2104, "w" -> 2205,
// "l" -> 2392, "u" -> 2561, "g" -> 2626, "h" -> 2954, "e" -> 3244,
// "i" -> 3357, "f" -> 3446, "t" -> 4160, "m" -> 4196, "a" -> 4500,
// "b" -> 4724, "r" -> 5143, "d" -> 5198, "p" -> 6559, "c" -> 7831,
// "s" -> 9599}
//真想用python初始化

struct HTNode
{
    int weight;
    int parent, left, right;
    HTNode()=default;
    void display(){
        printf("%d\t %d\t %d\t %d\t\n", weight, parent, left, right);
    }
};
typedef char ** HuffmanCode;
string alphabet("xzyqkjvnowlugheiftmabrdpcs ,.");     int len = alphabet.length();
const int Weight[] = {19, 137, 248, 412, 577,
                      711, 1206, 1698, 2104, 2205,
                      2392, 2561, 2626, 2954, 3244,
                      3357, 3446, 4160, 4196, 4500,
                      4724, 5143, 5198, 6559, 7831,
                      9599, 9999, 10000, 10001
                     };

void HuffmanCoding(vector<HTNode> &HT, vector<string> &HC, const int* Weight,  int n){
    if(n<2) return;
    int m = 2*n - 1;
    HT.resize(m+1);//0不用
    for(int i=1; i<=n; i++) HT[i].weight = Weight[i-1];

    for(int i=n+1; i<=m; i++){
        int w1=MAX_VALUE, w2=MAX_VALUE, p1=-1, p2=-1;
        for(int j=1; j<i; j++){
            if(HT[j].parent == 0){
                //如果权值相同，先取前面的节点 所以是《 而不是《=
                if(HT[j].weight<w1 ){//p1是当前轮权重最小的 节点的下标
                    p2 = p1;  w2 = w1;
                    p1 = j;  w1=HT[j].weight;
                }else if(HT[j].weight<w2){//p2是当前轮权重次小的 节点的下标
                    p2 = j;  w2=HT[j].weight;
                }
            }
        }
        HT[p1].parent = i; HT[p2].parent = i;
        HT[i].left = p1; HT[i].right = p2;//小的在左边
        HT[i].weight = HT[p1].weight + HT[p2].weight ;

    }
    int ic = 0;
    for(auto i : HT){
        cout << ic<< " "; i.display();
        ++ic;
    }
    HC.resize(n+1); string temp;  temp.resize(n+1);  int p=m, cdlen=0;
    for(int i=1; i<=m; i++) HT[i].weight = 0;
    while(p){
        int &flag = HT[p].weight;
        if(flag==0){//第一次朝左
            flag=1;
            if(HT[p].left != 0) {p=HT[p].left;  temp[cdlen++] = '0';   }//因为当退回父节点时上一个节点的多出来的0,1就废了。不能temp += '0'
            else if(HT[p].right == 0){//Huffman树只有度为0，2的节点， 这表明到了叶子了
                HC[p].assign(temp, 0, cdlen);
            }
        }else if(flag==1){
            flag=2;
            if(HT[p].right != 0) {p=HT[p].right;  temp[cdlen++] = '1';   }
        }else{
            flag=0; p= HT[p].parent;  --cdlen;
        }

    }
//    for(auto i : HC){
//        cout << i << endl;
//    }
    for (int i = 0; i < n; i++) {
		cout << alphabet[i] << ": " << HC[i+1] << endl;
	}
}

void HuffmanEncode(vector<string> &HC, const string &text, string &HuffmanText){HuffmanText.clear();
    for(char i : text){
        int pos = alphabet.find(i);
        if(pos != -1)
            HuffmanText.append(HC[pos+1]);
        else
            cout << "error, 超出了字母表!!"<< endl;
    }
}

void HuffmanDecode(vector<string> &HC, const string &HuffmanText,  string &text){text.clear();
    map<string, char> HCMap;
    int n =HC.size();
    for(int i=1; i<n; i++){
        HCMap[HC[i]] = alphabet[i-1];
    }
//    for(pair<string, char> i : HCMap){
//        cout << i.first << ": " << i.second << endl;
//    }

    int length = HuffmanText.length();
//    int pos = 0;
    for(int i=0; i<length; ){
        for(int j=1; j<n; j++){
            string sTmp = HuffmanText.substr(i, j);
//            cout << sTmp << endl;
            if( HCMap.find(sTmp) != HCMap.end() ){
                text+=HCMap[sTmp];
                i += j;
                break;
            }
        }
    }
}


void testString();
int main()
{
//    testString();
    vector<string> HC;
    vector<HTNode> HT;
    HuffmanCoding(HT, HC, Weight, len);
    string text="hello world, i love you.", HuffmanText, res;
    HuffmanEncode(HC, text, HuffmanText);
    cout << HuffmanText << endl;
//    testString();
    HuffmanDecode(HC, HuffmanText, res);
    cout << res;
//    int wBook[] = {2,3,5,5}; int n=4;
//    HuffmanCoding(HT, HC, wBook, n);

    return 0;
}
void testValue(const char* Value, int n) {
	for (int i = 0; i < n; i++) {
		cout << Value[i] << ": " << Weight[i] << endl;
	}
}

void testMap(vector<string> &HC){
    map<string, char> HCMap;
    int n =HC.size();
    for(int i=0; i<n; i++){
        HCMap[HC[i]] = alphabet[i];
    }
    for(pair<string, char> i : HCMap){
        cout << i.first << ": " << i.second << endl;
    }
}
void testString(){
    string s = "Hello World";
    cout << s.find('e') << endl;

}