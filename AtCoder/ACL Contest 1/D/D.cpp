#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=200005;
int n,k;
int x[N];
int Q;
int pre[N][20],nxt[N][20];
long long sp[N][20],sn[N][20];
void solve()
{
    int l,r;
    scanf("%d%d",&l,&r);
    int cnt=1;
    for(int i=log2(n),u=l;i>=0;i--)
        if(nxt[u][i]<=r) cnt+=1<<i,u=nxt[u][i];
    long long sum=cnt+r-l;
    for(int i=log2(n),u=l;i>=0;i--)
        if((cnt-1)&(1<<i)) sum-=sn[u][i],u=nxt[u][i];
    for(int i=log2(n),u=r;i>=0;i--)
        if((cnt-1)&(1<<i)) sum+=sp[u][i],u=pre[u][i];
    printf("%lld\n",sum);
    return;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    pre[0][0]=0;
    for(int i=n,j=n;i>=1;i--)
    {
        while(j>=1&&x[i]-x[j]<k) j--;
        pre[i][0]=j;
    }
    nxt[n+1][0]=n+1;
    for(int i=1,j=1;i<=n;i++)
    {
        while(j<=n&&x[j]-x[i]<k) j++;
        nxt[i][0]=j;
    }
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i<=n;i++)
            pre[i][j]=pre[pre[i][j-1]][j-1],nxt[i][j]=nxt[i][j-1]<=n?nxt[nxt[i][j-1]][j-1]:n+1;
    for(int i=1;i<=n;i++)
        sp[i][0]=pre[i][0],sn[i][0]=nxt[i][0];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i<=n;i++)
            sp[i][j]=sp[pre[i][j-1]][j-1]+sp[i][j-1],sn[i][j]=sn[nxt[i][j-1]][j-1]+sn[i][j-1];
    scanf("%d",&Q);
    while(Q--)
        solve();
    return 0;
}