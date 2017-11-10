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
//        case 4:
//            merge_sort(b, n);
//            break;
        case 5:
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


void merge_sort(int *a, int n);


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

void show_menu()
{
    printf("1:insert_sort\n");
    printf("2:shell_sort\n");
    printf("3:quick_sort\n");
    printf("4:merge_sort\n");
    printf("5:exit\n");
    printf("输入你的选择\n");
    cin >> choice;
}
