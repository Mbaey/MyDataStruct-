#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define  OK		1
#define  ERROR		-1
#define  MAX_SIZE	100
#define  LIST_INCREMENT	10
typedef  int	Status;
typedef  int	ElemType;
//c���԰汾
//Status Init_SqList( ArrayList *L );
//Status Push_SqList( ArrayList *L, ElemType e);
//Status Insert_SqList( ArrayList *L, int i, ElemType e );
//ElemType  Delete_SqList( ArrayList *L, int i );
class ArrayList
{
public:
    //���ֱ����vector�ͷ���ܶ���
	ElemType	*array;
	int		length=0;
    int Max_size;

    ArrayList();
    ~ArrayList();
    Status push(ElemType e);
    ElemType get(int index);
    void display();

    Status erase(int index);
    Status insert(int index, ElemType e);
    Status update(int index, ElemType e);
    int search(ElemType e);

};

ArrayList::ArrayList(){
//    cout << "constructor" << endl;
//    Elem_array = ( ElemType * ) malloc( MAX_SIZE * sizeof(ElemType) );
    array = new ElemType[MAX_SIZE];
	if ( !array )	exit(ERROR);
	else { length = 0; Max_size = MAX_SIZE;}
}
ArrayList::~ArrayList(){
    cout << "destructor" << endl;
//    free(Elem_array);
    delete [] array;
}

Status ArrayList::push(ElemType e){
    if(length >= MAX_SIZE){
        //�ȸ��ơ��ٿ�����ȥ
        //����malloc ��relloc����
//        cout << "//�ȸ��ơ��ٿ�����ȥ" << endl;
        ElemType temp[Max_size];
        memcpy(temp, array, sizeof(temp));
        Max_size += LIST_INCREMENT;
        delete [] array;
        array = new ElemType[Max_size];
        if(!array) return ERROR;
        memcpy(array, temp, sizeof(temp));
    }
    array[length++] = e;
    return OK;
}
ElemType ArrayList::get(int index){
    if(index < length){
        return array[index];
    }else{
        cout << "�±�Խ��" << endl;
        return ERROR;
    }
}
void ArrayList::display(){
    int i;
    for(i=0; i<length-1; i++) cout << array[i] << " ";
    cout << array[length-1] << endl;
}

Status ArrayList::erase(int index){
    if(index < length){
        for(int i=index; i<length-1; i++){
            array[i] = array[i+1];
        }
        array[length--]=0;
        return OK;
    }else{
        cout << "�±�Խ��" << endl;
        return ERROR;
    }
}
//���ܲ嵽���һ��λ��
Status ArrayList::insert(int index, ElemType e){

    if(index < length && length + 1<MAX_SIZE){
        length++;
        for(int i=length-1; i>index; i--){
            array[i] = array[i-1];
        }
        array[index] = e;

        return OK;
    }else{
        cout << "�±�Խ��" << endl;
        return ERROR;
    }
}

Status ArrayList::update(int index, ElemType e){
    if(index < length){
        array[index] = e;
        return OK;
    }else{
        cout << "�±�Խ��" << endl;
        return ERROR;
    }
}
int ArrayList::search(ElemType e){
    int i;
    for(i=0; i<length; i++)
    {
        if(array[i] == e){
            return i;
        }
    }
    return ERROR;
}
void union_Array(ArrayList *L, int a[], int b[], int aLen, int bLen){
    int n = aLen + bLen;
    int i, c=0, d=0;
    for(i=0; i<n; i++){
        if(c==aLen){
            (*L).push(b[d++]);
        }else if(d==bLen){
            (*L).push(a[c++]);
        }else if(a[c]>b[d]){
            (*L).push(b[d++]);
        }else{
            (*L).push(a[c++]);
        }
    }
}


int main()
{
    ArrayList myList;

    int a[] = {1,3,5,7,9};
    int b[] = {0,2,4,6,8};
    union_Array(&myList, a, b, 5, 5);
    myList.push(10);
    myList.push(100);
    myList.push(1000);
    myList.erase(0);
    myList.insert(1, 888);
    myList.update(2, 666);
    myList.display();

    cout << myList.search(888) << endl;
	return(0);
}

