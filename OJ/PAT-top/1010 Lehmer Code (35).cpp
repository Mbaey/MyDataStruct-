#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
// https://blog.csdn.net/liuchuo/article/details/79265631
//https://blog.csdn.net/baidu_32157201/article/details/52327137
using namespace std;
vector<int> d;
const int N= 100000;
int n, a[N], b[N];
//set<int> s;
int main()
{
    //freopen("1.txt", "r", stdin);
    cin >> n;
    for(int i=0; i<n; i++)
        scanf("%d", a+i);

    /*实现了 O（logn）的查找 和
    O（n）的插入  要移动元素*/
    for(int i=n-1; i>=0; i--){
        int &t=a[i];
        auto posi = upper_bound(d.begin(), d.end(), t);
        b[i] =posi  - d.begin();
        d.insert(posi, t);
    }
    for(int i=0; i<n-1; i++){
        printf("%d ", b[i]);
    }
    printf("0");

    return 0;
}

/*demo.push_back(13); 它是顺序容器！
    demo.push_back(23);
    demo.push_back(213);
    int dc = demo.begin() - demo.end();
    cout << dc;
    */
//set的迭代器不能作减法。。  它是关联容器！
//    s.insert(10);
//    s.insert(100);
//    s.insert(1000);
//    auto end  =s.end();
//    auto begin  =s.begin();
//
//    int num;
//    while()
//    cout << * (end)<< endl;
//    cout << *s.upper_bound(5);
