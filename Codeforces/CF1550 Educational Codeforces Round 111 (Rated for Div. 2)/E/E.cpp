#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200005,K=17;
int n,k;
char s[N];
int sum[N],sumc[N][K];
bool check(int x)
{
    static int nxt[N][K];
    for(int j=0;j<k;j++)
        nxt[n+1][j]=n+1;
    for(int i=n;i>=1;i--)
        for(int j=0;j<k;j++)
            if(i+x-1<=n&&sum[i+x-1]-sum[i-1]==sumc[i+x-1][j]-sumc[i-1][j]) nxt[i][j]=i+x-1;
            else nxt[i][j]=nxt[i+1][j];
    static int f[1<<K];
    fill(f,f+(1<<k),n+1);
    f[0]=0;
    for(int S=1;S<(1<<k);S++)
        for(int i=0;i<k;i++)
            if(S&(1<<i))
            {
                if(f[S^(1<<i)]<=n) f[S]=min(f[S],nxt[f[S^(1<<i)]+1][i]);
            }
    return f[(1<<k)-1]<=n;
}
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1];
        for(int j=0;j<k;j++)
            sumc[i][j]=sumc[i-1][j];
        if('a'<=s[i]&&s[i]<='z') sum[i]++,sumc[i][s[i]-'a']++;
    }
    int l=0,r=n,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d",ans);
    return 0;
}
