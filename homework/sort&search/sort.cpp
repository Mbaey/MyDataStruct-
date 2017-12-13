#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
#define MAX_VALUE 10
void in(int *a, int &n);
void out(int *a, int n);
void insert_sort(int *a, int n);
void shell_sort(int *a, int n);
void quick_sort(int *a, int n);
void merge_sort(int *a, int n);
int choice=0;
void show_menu();
int Partition(int *a, int left, int right);
void quick_sort(int *a, int left, int right);
void Msort(int sr[], int tr[], int begin, int end);
void two_path_merge(int *sr, int *tr, int begin, int m, int end);

void HeapAdjust(int a[], int s, int m);
void heap_sort(int a[], int n);

int main()
{
//    freopen("1.txt", "r", stdin);
    int a[MAX_VALUE]= {99, 1 ,24 ,35 ,36 ,40 ,28}, n=7;
    int b[MAX_VALUE];
//    in(a, n);


    show_menu();
    while(1)
    {
        system("cls");
        for(int i=0; i<n; ++i) b[i] = a[i];
        switch(choice)
        {
        case 1:
            insert_sort(b, n);
            break;
        case 2:
            shell_sort(b, n);
            break;
        case 3:
            quick_sort(b, n);
            break;
        case 4:
            merge_sort(b, n);
            break;
        case 5:
            heap_sort(b, n);
            break;
        case 6:
            exit(0);
            break;
        }
        show_menu();

    }

    quick_sort(a, n);
    out(a, n);
    return 0;
}
void in(int *a, int &n)
{
    cin >> n;
    for(int i=0; i<n; ++i)
    {
        cin >> a[i];
    }
}
void out(int *a, int n)
{
    for(int i=0; i<n; ++i)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}
void out(int *a, int s, int e)
{
    for(int i=s; i<=e; ++i)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}


void quick_sort(int *a, int n){
    quick_sort(a, 0, n-1);
}
int Partition(int *a, int left, int right){
    int t = a[left];
    while(left < right){
        while(left < right && a[right] >= t )  --right;
        a[left] = a[right];
        while(left < right && a[left] <= t )  ++left;
        a[right] = a[left];
    }
    a[left] = t;
    out(a, 7);
    return left;
}
void quick_sort(int *a, int left, int right){
    int loc=0;
    if(left < right){
        loc = Partition(a, left, right);//以位置为left的元素为基准，比它小的放前面，比它大的放后面。 返回left之后的位置
        quick_sort(a, left, loc-1);
        quick_sort(a, loc+1, right);
    }
}





void shell_sort(int a[], int n)
{
    int increment=n/2;
    out(a, n);
    while(increment!=0)
    {
        for(int i=increment; i<n; i+=1)
        {
            int t = a[i];
            if(a[i] < a[i-increment])
            {
                int j;
                for(j=i; j>=increment && a[j] < a[j-increment]; j-=increment)
                {
                    a[j] = a[j-increment];
                }
                a[j] = t;
            }
        }
        out(a, n);
        increment /= 2;
    }
}
void insert_sort(int *a, int n)
{
    for(int i=1; i<n; ++i)
    {
        out(a, i);
        int t = a[i];
        //if(a[i] < a[i-1])
        {
            int j;
            for(j=i; j>0 && a[j] < a[j-1]; j--)
            {
                a[j] = a[j-1];
            }
            a[j] = t;
        }
    }
}

void two_path_merge(int *sr, int *tr, int begin, int m, int end){
    //将有序的 sr[begin~m] 与sr[m+1~end] 合并成tr
    int i=begin, r=m+1, l=begin;
    for(; r<=end && l<=m; ++i){
        if(sr[l] > sr[r]) tr[i] = sr[r++];
        else tr[i] = sr[l++];
    }
    while(r<=end) tr[i++] = sr[r++];
    while(l<=m) tr[i++] = sr[l++];

    cout << "sr: "; out(sr, begin, end);
    cout << "tr: ";  out(tr, begin, end);
}
void Msort(int sr[], int tr[], int begin, int end){
    if(begin==end) tr[end]=sr[end];
    else{
        int tr2[MAX_VALUE]={0};
        int m = (begin+end)/2;
        Msort(sr, tr2, begin, m);
        Msort(sr, tr2, m+1, end);
        two_path_merge(tr2, tr, begin, m, end);
    }
}

void merge_sort(int *a, int n){
    int b[n]={0};
    Msort(a, b, 0, n-1);
    a = b;
}

void show_menu()
{
    printf("1:insert_sort\n");
    printf("2:shell_sort\n");
    printf("3:quick_sort\n");
    printf("4:merge_sort\n");
    printf("5:heap_sort\n");
    printf("6:exit\n");
    printf("输入你的选择\n");
    cin >> choice;
}
//最大堆 是降序
void HeapAdjust(int a[], int s, int m){
    //使s到a【1~m】上应该的位置。————往下沉
    a[0] = a[s];//哨兵
    for(int j=s*2; j<=m; j*=2){
        if(j<m && a[j]<a[j+1]) j++;
        if(a[0]> a[j]) break;   // s比孩子大了。 直接交换  最大堆！！
        a[s] = a[j]; s = j;   //小孩子上浮
    }
    a[s] = a[0];//爸爸下来
}

void heap_sort(int a[], int n){
    int b[n+1]={0};
    for(int i=0; i<n; i++) b[i+1] = a[i];
    for(int i=n/2; i>0; i--)
        HeapAdjust(b, i, n);
    for(int i=n; i>1; i--){
        b[0] = b[1];
        b[1] = b[i];
        b[i] = b[0];
        HeapAdjust(b, 1, i-1);
        out(b, 1, n);
    }
    out(b, 1, n);

}