#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200005;
int T;
int n;
char s[N];
int f[N][2];
void solve()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1') f[i][1]=f[i-1][0]+1,f[i][0]=0;
        else if(s[i]=='0') f[i][0]=f[i-1][1]+1,f[i][1]=0;
        else if(s[i]=='?') f[i][1]=f[i-1][0]+1,f[i][0]=f[i-1][1]+1;
        ans+=max(f[i][0],f[i][1]);
    }
    printf("%lld\n",ans);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}