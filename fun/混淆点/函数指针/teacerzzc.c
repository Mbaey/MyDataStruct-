
/* 使用函数指针的回调函数技巧，设计一个能排序int 和char 数组的sort()函数 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define   FALSE  0
#define   TRUE   1

//sort 函数
void sort( const void *, const int number, unsigned width,
               int(*compare)(void *, void *),
               void (*swap)(void *,void *));

int compare_int(void *, void *);
int compare_char(void *, void  *);
void swap_int(void *, void *);
void swap_char(void *, void  *);
void print(const void *_tmp, int num, int width,
               void (*_printf)(const void *));
void print_int(const void * );
void print_char(const void *);
int main(void)
{
     int  num = 10;
     int  a_int[10] = {9, 2, 3, 8, 1, 5, 6, 4, 7, 12};
     char c_char[10] = {'g', 'h', 't', 'a', 'd', 'w', 'q', 'b', 'm', 'c'};

     //使用sort对上述两个数组进行排序
     sort(a_int , num,  sizeof (int),  compare_int,    swap_int );
     sort(c_char, num, sizeof(char), compare_char, swap_char);

     //打印排序结果
     print(a_int,   num,  sizeof(int),    print_int);
     print(c_char, num,  sizeof(char), print_char);
     getchar();
    return 0;
}
void sort( const void *, const int number, unsigned width,
               int (*compare)(void *, void *),
               void (*swap)(void *,void *));
void print(const void *_tmp, int num, int width,
               void (*_printf)(const void *));
//the sort function
/*sort排序函数使用普通的选择排序*/

void sort(const void *_tmp, const int number, unsigned width,
          int(*compare)(void *,void *),
          void (*swap)(void *,void *))
{
    int i, j, small;

    for(i = 0; i < number - 1; i++)
    {
        small = i;
        for(j = i+1; j < number; j++)
            if(compare((char *)_tmp + j*width, (char *)_tmp+ small* width))
                small = j;

        if(small != i)
            swap((char *)_tmp + i*width, (char *)_tmp + small*width);
    }
}
//compare int function
int compare_int( void * tmp_a, void *tmp_b)
{
    if (*(int *)tmp_a < *(int *)tmp_b)
        return TRUE;
    else
        return FALSE;
}

//compare char  function
int compare_char( void * tmp_a, void *tmp_b)
{
    if (*(char *)tmp_a < *(char *)tmp_b) //使用char的比较方式或其他strcmp函数

        return TRUE;
    else
        return FALSE;
}
//swap int function
void swap_int( void * tmp_a, void *tmp_b)
{
    int temp;

    temp               =  *(int *)tmp_a;
    *(int *)tmp_a  =  *(int *)tmp_b;
    *(int *)tmp_b  =  temp;
}

//swap char function
void swap_char( void * tmp_a, void *tmp_b)
{
    char temp;

    temp                =  *(char *)tmp_a;
    *(char *)tmp_a =  *(char *)tmp_b;
    *(char *)tmp_b =  temp;
}
//printf function
void print(const void *_tmp, int num, int width,
             void (*_printf)(const void *))
{
    int  i;
    for(i = 0; i < num; i++)
    {
        _printf((char *)_tmp + i*width);
        printf(" ");
    }
    printf("\n");
}

void print_int(const void *_tmp)
{
    printf("%d", *(int*)_tmp);
}

void print_char(const void *_tmp)
{
    printf("%c", *(char*)_tmp);
}
