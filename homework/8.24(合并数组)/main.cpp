#include <stdio.h>
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
class SqList
{
public:
	ElemType	*Elem_array;
	int		length;
    int Max_size;

    SqList();
    ~SqList();
    Status push(ElemType e);
    ElemType get(int index);
    void display();
    ElemType pop();
};

SqList::SqList(){
//    cout << "constructor" << endl;
//    Elem_array = ( ElemType * ) malloc( MAX_SIZE * sizeof(ElemType) );
    Elem_array = new ElemType[MAX_SIZE];
	if ( !Elem_array )	exit(ERROR);
	else { length = 0; Max_size = MAX_SIZE;}
}
SqList::~SqList(){
    cout << "destructor" << endl;
//    free(Elem_array);
    delete [] Elem_array;
}

Status SqList::push(ElemType e){
    if(length >= MAX_SIZE){
        //先复制。再拷贝回去
        //还是malloc 与relloc方便
        cout << "//先复制。再拷贝回去" << endl;
        ElemType temp[Max_size];
        memcpy(temp, Elem_array, sizeof(temp));
        Max_size += LIST_INCREMENT;
        Elem_array = new ElemType[Max_size];
        if(!Elem_array) return ERROR;
        memcpy(Elem_array, temp, sizeof(temp));
    }
    Elem_array[length++] = e;
    return OK;
}
ElemType SqList::get(int index){
    if(index < length){
        return Elem_array[index];
    }else{
        cout << "下标越界" << endl;
        return ERROR;
    }
}
void SqList::display(){
    int i;
    for(i=0; i<length-1; i++) cout << Elem_array[i] << " ";
    cout << Elem_array[length-1] << endl;
}

Status Init_SqList( SqList *L )
{
//    cout << "init" << endl;
	L->Elem_array = ( ElemType * ) malloc( MAX_SIZE * sizeof(ElemType) );
	if ( !L->Elem_array )
		return(ERROR);
	else { L->length = 0;    return(OK);  }
}

Status Push_SqList( SqList *L, ElemType e)
{
    if ( L->length >= MAX_SIZE )
	{
		printf( "线性表溢出!\n" );
		return(ERROR);
	}

}


Status Insert_SqList( SqList *L, int i, ElemType e )
{
	int j;
	if ( i < 0 || i > L->length - 1 )
		return(ERROR);
	if ( L->length >= MAX_SIZE )
	{
		printf( "线性表溢出!\n" );
		return(ERROR);
	}

    for ( j = L->length - 1; j >= i - 1; --j )
    {
        L->Elem_array[j + 1] = L->Elem_array[j];
    }

/*  i-1位置以后的所有结点后移  */
	L->Elem_array[i - 1] = e; /*  在i-1位置插入结点  */
	L->length++;
	return(OK);
}


ElemType  Delete_SqList( SqList *L, int i )
{
	int k;   ElemType x;
	if ( L->length == 0 )
	{
		printf( "线性表L为空!\n" ); return(ERROR);
	}else if ( i < 1 || i > L->length )
	{
		printf( "要删除的数据元素不存在!\n" );
		return(ERROR);
	}else { x = L->Elem_array[i - 1]; /*保存结点的值*/
		for ( k = i; k < L->length; k++ )
			L->Elem_array[k - 1] = L->Elem_array[k];
		/*  i位置以后的所有结点前移  */
		L->length--;  return(x); }
}

void union_Array(SqList *L, int a[], int b[], int aLen, int bLen){
    int n = aLen + bLen;
    int i, c=0, d=0;
    for(i=0; i<n; i++){
        if(a[c]>b[d]){
            (*L).push(b[d++]);
        }else{
            (*L).push(a[c++]);
        }
    }
}


int main()
{
/*	freopen("1.txt", "r", stdin); */
    SqList myList;

//    myList.push(10);
//    cout << myList.get(0) << endl;
//    myList.push(100);
//    cout << myList.get(0) << endl;
//    cout << myList.get(1) << endl;

    int a[] = {1,3,5,7,9};
    int b[] = {0,2,4,6,8};
    union_Array(&myList, a, b, 5, 5);
    myList.push(1);
    myList.push(1);
    myList.push(1);
    myList.display();
	return(0);
}


