#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000001;
const int MOD=1000000007;
int T;
int n;
char s[N];
int nxt[N],num[N];
long long ans;
void solve()
{
    int j=0;
    ans=1;
    num[1]=1;
    for(int i=2;i<=n;i++)
    {
        while(j>0&&s[j+1]!=s[i]) j=nxt[j];
        if(s[j+1]==s[i]) j++;
        nxt[i]=j,num[i]=num[j]+1;
    }
    j=0;
    for(int i=2;i<=n;i++)
    {
        while(j>0&&s[j+1]!=s[i]) j=nxt[j];
        if(s[j+1]==s[i]) j++;
        while(j*2>i&&nxt[j]) j=nxt[j];
        ans=ans*(num[j]+1)%MOD;
    }
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        n=strlen(s+1);
        solve();
        printf("%lld\n",ans);
    }
    return 0;
}