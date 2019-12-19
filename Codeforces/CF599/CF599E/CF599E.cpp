#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=14,Q=101;
int n,m,q;
long long dp[N][1<<N];
bool edge[N][N];
int a[Q],b[Q],c[Q];
int lowbit(int x)
{
    return x&(-x);
}
inline bool in(int i,int S)
{
    return ((S>>i)&1);
}
bool check(int u,int k)
{
    for(int i=0;i<n;i++)
        if(i!=u)
        {
            for(int j=0;j<n;j++)
                if(j!=u)
                    if(edge[i][j]&&(in(i,k)^in(j,k))) return false;
        }
    return true;
}
bool judge(int u,int k)
{
    for(int i=1;i<=q;i++)
    {
        if(c[i]==u&&in(a[i],k)&&in(b[i],k)) return false;
        if(in(c[i],k)&&(!in(a[i],k)||!in(b[i],k))) return false;
    }
    return true;
}
long long DP(int u,int S)
{
    if(dp[u][S]!=-1) return dp[u][S];
    dp[u][S]=0;
    int status=S-(1<<u);
    int t;
    for(t=0;t<n;t++)
        if(in(t,status)) break;
    for(int k=status;k;k=(k-1)&status)
        if(in(t,k))
        {
            if(!check(u,k)) continue;
            int v,cnt=0;
            for(int i=0;i<n;i++)
                if(edge[u][i]&&in(i,k)) cnt++,v=i;
            if(cnt>=2) continue;
            bool flag=true;
            if(!judge(u,k)) continue;
            if(cnt==1) dp[u][S]+=DP(v,k)*DP(u,S-k);
            else if(cnt==0)
            {
                for(v=0;v<n;v++)
                    if(in(v,k)) dp[u][S]+=DP(v,k)*DP(u,S-k);
            }
        }
    return dp[u][S];
}

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--,y--;
        edge[x][y]=edge[y][x]=true;
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        a[i]--,b[i]--,c[i]--;
    }
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
        dp[i][1<<i]=1;
    printf("%lld",DP(0,(1<<n)-1));
    return 0;
}