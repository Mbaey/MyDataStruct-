//#include <stdio.h>
//#include <iostream>
//#include <cstring>
//#include <cstdlib>
//
//using namespace std;
//
//template <class T>
//int getArrayLen(T& array)
//{
//    return (sizeof(array) / sizeof(array[0]));
//}
//
//template<class T,size_t N>
//unsigned int LengthofArray(T (&array)[N]){
//    return sizeof(array) / sizeof(T);
//}
//int main(){
//    int *a = new int[2];
//
//    a[1] = 2;
//
//    cout << a[1] << endl;
//
//    int b[2];
//    memcpy(b, a, sizeof(b));
//    a = new int [3];
//    memcpy(a, b, sizeof(b));
//
//    a[2] = 333;
//    cout << a[2]<< endl;
//    cout << a[1]<< endl;
//
//    delete []a;
//    return 0;
//}
//
