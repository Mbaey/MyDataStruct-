#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[105][5];
char s[105];
int len;
//https://blog.csdn.net/lmhacm/article/details/79723475
int judge1(int st,int en)
{
    dp[st][0]=1;
    dp[en][1]=0;
    while(st!=en)
    {
        st=(st+1)%len;
        if(s[st]-1==s[(st-1+len)%len])//当前为B，前者为A
        {
            dp[st][0]=dp[(st-1+len)%len][1];
            dp[st][1]=0;
        }
        else if(s[st]+1==s[(st-1+len)%len])//当前为A，前者为B
        {
            dp[st][0]=dp[(st-1+len)%len][0];
            dp[st][1]=dp[(st-2+len)%len][0]+dp[(st-2+len)%len][1];
            if(dp[st][1]==0)
                dp[st][1]=1;
        }
        else//当前与前者相同
        {
            dp[st][0]=dp[(st-1+len)%len][0]+dp[(st-1+len)%len][1];
            dp[st][1]=0;
        }
    }
    return dp[st][0]+dp[st][1];
}
 
int judge2(int st,int en)
{
    int t=2;
    if(s[st]=='B')
    {
        if(s[(st+1)%len]=='A')
        {
            st=(st+2)%len;
            t+=2;
        }
        else
            return 0;
    }
    if(s[en]=='A')
    {
        if(s[(en-1+len)%len]=='B')
        {
            en=(en-2+len)%len;
            t+=2;
        }
        else
            return 0;
    }
    if(t>=len)
        return 1;
    memset(dp,0,sizeof(dp));
    dp[st][0]=1;
    dp[en][1]=0;
    while(st!=en)
    {
        st=(st+1)%len;
        if(s[st]-1==s[(st-1+len)%len])//当前为B，前者为A
        {
            dp[st][0]=dp[(st-1+len)%len][1];
            dp[st][1]=0;
        }
        else if(s[st]+1==s[(st-1+len)%len])//当前为A，前者为B
        {
            dp[st][0]=dp[(st-1+len)%len][0];
            dp[st][1]=dp[(st-2+len)%len][0]+dp[(st-2+len)%len][1];
            if(dp[st][1]==0)
                dp[st][1]=1;
        }
        else//当前与前者相同
        {
            dp[st][0]=dp[(st-1+len)%len][0]+dp[(st-1+len)%len][1];
            dp[st][1]=0;
        }
    }
    return dp[st][0]+dp[st][1];
}
 
int main()
{
    int i;
    int ans;
    while(scanf("%s",s)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]-1==s[i+1])
                break;
        }
        ans=judge1((i+2)%len,(i-1+len)%len)+judge2((i+2)%len,(i-1+len)%len);
        cout<<ans<<endl;
    }
    return 0;
}
