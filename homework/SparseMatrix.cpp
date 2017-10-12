#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
#define  OK		1
#define  ERROR		-1
#define  MAX_COLUMN 10
const int colume= 3;

template <class T>//��ʵ�����Ͼ������־����ˣ���
struct Triple{
    int r, c;//row colume
    T value;
    Triple()=default;
    Triple(int i, int j, T e): r(i), c(j), value(e){};
    void display(){ printf("Row.%d  Column.%d ", r, c); cout << value << endl;}
    void add(Triple b, Triple &res){
        if(r==b.r && c==b.c)  {  res.r=r; res.c=c;  res.value=value+b.value;}
    }
    int cmp(Triple b){//���λ�ò���ͬ���Ƚ�λ�ô�С��λ�ÿ�ǰ�Ĵ�.������
        if(r < b.r){ return -1;}
        else if(r > b.r){ return 1;}
        else if(c < b.c){ return -1;}
        else if(c > b.c){ return 1;}
        else{ return 0;}
    }
};
template <class T>
struct SparseMatrix{
    int mr, mc, mn;//��,��,����
    vector<Triple<T> > data;

    SparseMatrix()=default;
    SparseMatrix(int i, int j, int n): mr(i), mc(j), mn(n){ data.resize(mn);};
    SparseMatrix(int r, int c, T d[][MAX_COLUMN]): mr(r), mc(c), mn(0){
        for(int i=0; i<mr; i++){
            for(int j=0; j<mc; j++){
                if(d[i][j] != 0){
                    ++mn;
                    Triple<T> t(i,j,d[i][j]);
                    data.push_back(t);
                }
            }
        }
    };
    int empty(){
        if(mr==0 && mc==0){
            return OK;
        }
        return ERROR;
    }
    void display(){
        for(int i=0; i<mn; i++){
            data[i].display();
        }
    }
    void display2(){
        for(int i=0; i<mr; i++){
            for(int j=0; j<mc; j++){
                printf("%d\t", get(i, j));
//                cout << get(i, j) << " ";
            }putchar('\n');
        }
    }
    T get(int r, int c){
        if(mr<r || mc<c) return ERROR;
        for(int i=0; i<mn; i++){
            if(data[i].r == r && data[i].c == c)  return data[i].value;
        }
        return 0;
    }

    int set(int r, int c, T e){
        if(mr<r || mc<c) return ERROR;
        int loc=0;
        for(int i=0; i<mn; i++){
//            data[i].display();
            if(data[i].r == r && data[i].c == c)  { data[i].value = e; return OK;}
            else if(data[i].r == r && data[i].c < c)  { loc = i; }
            else if(data[i].r == r && data[i].c > c)  { break; }
        }
        ++loc;
        Triple<T> t(r,c,e);

        data.insert(data.begin() + loc, t);
        ++mn;
        return OK;
    }


    int AddSMatrix(SparseMatrix b, SparseMatrix &res){
        if(mr != b.mr || mc != b.mc){   return ERROR;   }
        res.mr = mr;        res.mc = mc;     res.mn=0;   res.data.clear();//���res;
        int i=0, j=0;
        Triple<T> t;
        while(i<mn && j<b.mn){//ѭ��a����
            if(data[i].cmp(b.data[j]) == 1){//a > b
                res.data.push_back(b.data[j]);
                ++j;
            }else if(data[i].cmp(b.data[j]) == -1){
                res.data.push_back(data[i]);
                ++i;
            }else{
                if(data[i].value + b.data[j].value != 0){
                    data[i].add(b.data[j], t);
                    res.data.push_back(t);
                }else{
                    res.mn--;
                }
                ++i; ++j;
            }
            ++res.mn;
        }

        while(i<mn ){
            res.data.push_back(data[i++]);
        }
        while(j<b.mn ){
            res.data.push_back(b.data[j++]);
        }
        return OK;

    }
    //int mr, mc, mn;//��,��,����
    int multiSMatrix(SparseMatrix b, SparseMatrix &res){
        if(mc != b.mr){   return ERROR;   }
        res.mr = mr;        res.mc = b.mc;     res.mn=0;   res.data.clear();//���res;
        if(res.empty() != 0){
            //rpos[row] ����res����ĵ�row�е�һ������Ԫ�� ctemp[row] ��ʾ��ǰ�и�Ԫ���ۼӺ�
            vector<int> numA(mr), rposA(mr+mc), numB(b.mr);
            vector<int> rposB(b.mr+1), rpos(b.mr), ctemp(b.mr);
            for(int i=0; i<mn; i++){               ++numA[data[i].r];  }//��rposA
            for(int i=1; i<=mc; i++){   rposA[i] = rposA[i-1] + numA[i-1]; }

            for(int i=0; i<b.mn; i++){             ++numB[b.data[i].r];   }
            for(int i=1; i<=b.mc; i++){   rposB[i] = rposB[i-1] + numB[i-1]; }


            for(int r=0; r<mr; r++){//��c�������

//                ctemp[r] = 0;
                for(auto i=ctemp.begin(); i<ctemp.end(); ++i)   *i=0;
                rpos[r] = res.mn + 1;
                int tp=0;
                if(r<mr){ tp=rposA[r+1];}//�����ǰ����tp��
                else{ tp=mn+1;}
                for(int p=rposA[r]; p < tp; ++p){
                    int brow=data[p].c, tq=0;//�ҵ���Ӧ���к�
                    if(  brow<b.mr ){ tq=rposB[brow+1];}
                    else{ tq=b.mn+1;}

                    for(int q=rposB[brow]; q<tq; ++q){
                        int ccol=b.data[q].c;
                        ctemp[ccol] += data[p].value * b.data[q].value;
                    }
                }

                for(int ccol=0; ccol<res.mc; ++ccol){
                    if(ctemp[ccol]){
                        res.mn++;
                        Triple<T> t(r , ccol, ctemp[ccol]);
                        res.data.push_back(t);
                    }
                }

            }
            return OK;
        }

    }

    void fastTransposeSMatrix(SparseMatrix &Transpose){
        Transpose.mr = mc;        Transpose.mc = mr;     Transpose.mn=mn;   Transpose.data.clear();//���res;
        Transpose.data.resize(mn);
        if(mn != 0){
            int num[MAX_COLUMN]={0}, cpot[MAX_COLUMN]={0};
            for(int c=0; c<mc; c++){ num[c]=0; cpot[c]=0;}
            for(int i=0; i<mn; i++){ ++num[data[i].c]; }//����ÿ�и���,  ����Ԫ��ʱ�������⣿����/**/
            cpot[0]=0;//�˴��±��0��ʼ�����򱨶��洦��
            for(int i=1; i<mc; i++){   cpot[i] = cpot[i-1] + num[i-1]; }
            for(int i=0; i<mn; i++){   int &p = cpot[data[i].c];
                Transpose.data[p].c = data[i].r;  Transpose.data[p].r = data[i].c;  Transpose.data[p].value = data[i].value;
                ++p;
            }
        }
    }

};

//void f(int d[][MAX_COLUMN]){
//    int n=3, m=3;
//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            cout << d[i][j] << " " ;
//        }putchar('\n');
//    }
//    putchar('\n');
//}
void showAdd(SparseMatrix<int> a, SparseMatrix<int> b){
    SparseMatrix<int> res;
    a.display();
    cout << endl;
    b.display();
    cout << endl;
    a.AddSMatrix(b, res);
    res.display();
}

void showTranspose(SparseMatrix<int> &a){
    SparseMatrix<int> res;
    a.fastTransposeSMatrix(res);
    cout << "ԭ����" <<endl;
    a.display();
    cout << endl;
    cout << "ת�ú����" <<endl;
    res.display();
}
void showMulti(){
    int d1[][MAX_COLUMN] = {  {3,0,0,5} , {0, -1, 0, 0}, {2, 0, 0, 0}};
    int d2[][MAX_COLUMN] = {  {0,2} , {1, 0}, {-2, -4}, {0, 0} };
    SparseMatrix<int> M(3, 4, d1), N(4, 2,d2), res;
    M.multiSMatrix(N, res);
    M.display2();
    putchar('\n');
    N.display2();
    putchar('\n');

    res.display2();
}

int main()
{
//    Triple<int> a(1,2, 10);
//    Triple<int> b(1,2, 10);
//    cout << a.cmp(b) << endl;//Test Cmp;

//    f(d);//Test how to �������鵽����;
    int d[][MAX_COLUMN] = {  {1,0,0,0} , {3, 0, 10, 0}, {0, 2, 0, 666}};
    SparseMatrix<int> M(3, 4, d), N(1,1,d), T;

//    N = M;//�Զ����� �������캯��������Ȼ���㣬��ʵ�ڲ���ԭ������

    M.display();
    M.display2();
    showTranspose(M);
    cout << endl;

    N = M;
    N.set(0,1, 10);
    N.set(1,0, -3);
    showAdd(M, N);
    putchar('\n');
    showMulti();
    return 0;
}
