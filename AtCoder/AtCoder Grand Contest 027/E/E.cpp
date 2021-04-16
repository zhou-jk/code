#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005;
const int MOD=1000000007;
int n;
char s[N];
int sum[N];
int f[N];
int nxt[N][3];
bool check()
{
    for(int i=2;i<=n;i++)
        if(s[i]==s[i-1]) return false;
    return true;
}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    if(check())
    {
        printf("1");
        return 0;
    }
    for(int i=1;i<=n;i++)
        if(s[i]=='a') sum[i]=(sum[i-1]+1)%3;
        else if(s[i]=='b') sum[i]=(sum[i-1]+2)%3;
    for(int j=0;j<=2;j++)
        nxt[n+1][j]=n+1;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=2;j++)
            nxt[i][j]=nxt[i+1][j];
        nxt[i][sum[i]]=i;
    }
    f[0]=1;
    for(int i=0;i<=n;i++)
        for(int j=1;j<=2;j++)
            f[nxt[i+1][(sum[i]+j)%3]]=(f[nxt[i+1][(sum[i]+j)%3]]+f[i])%MOD;
    int ans=0;
    for(int i=1;i<=n;i++)
        if((sum[n]-sum[i])%3==0) ans=(ans+f[i])%MOD;
    printf("%d",ans);
    return 0;
}