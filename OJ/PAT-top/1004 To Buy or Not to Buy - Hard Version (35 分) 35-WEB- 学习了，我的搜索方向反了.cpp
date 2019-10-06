//http://www.manongzj.com/blog/5-hqvqvfldxsmwckp.html
#include<bits/stdc++.h>
using namespace std;
int const N=100+10;
int num[N<<1],cnt[N<<1],n,ans=300,c[N][N<<1],sel[N];
string s,a[N];
void dfs(int x,int ex){
    if(ex>=ans) return;//这一步是我没有剪枝的！！，原来是我搜索方向反了，我依次去除某一串，more只会减少，无法剪枝！
    if(x>n) {
        int check=0;
        for(int i=48;i<130;i++)
            if(cnt[i]<num[i]) check=1;
        if(!check) ans=ex;
        return ;
    }
    int tmp=ex;
    for(int i=48;i<130;i++){
        if(cnt[i]>=num[i])
            ex+=c[x][i];
        else if(cnt[i]+c[x][i]>=num[i])  ex+=cnt[i]+c[x][i]-num[i];
        cnt[i]+=c[x][i];
    }
    sel[x]=1;
    dfs(x+1,ex);
    sel[x]=0;
    for(int i=48;i<130;i++)
        cnt[i]-=c[x][i];
    dfs(x+1,tmp);
}
int main(){
    cin>>s;
    for(int i=0;i<s.length();i++)
        num[s[i]]++;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=0;j<a[i].length();j++)
            cnt[a[i][j]]++,c[i][a[i][j]]++;
    }
    int sum=0;
    for(int i=0;i<200;i++)
        if(cnt[i]<num[i]){
            sum+=num[i]-cnt[i];
        }
    if(sum){
        printf("No %d\n",sum);
        return 0;
    }
    memset(cnt,0,sizeof(cnt));
    dfs(1,0);
    printf("Yes %d\n",ans);
    return 0;
}
