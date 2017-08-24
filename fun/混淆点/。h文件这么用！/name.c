#include<stdio.h>
#include "name.h"

//void say_hello(char *a)
//{
//    printf("Hello %s", a);
//}
extern void say_hello(const char *str)
{
    printf("Hello %s\n", str);
}
