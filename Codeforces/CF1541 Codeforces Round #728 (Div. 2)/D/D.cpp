#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int N=205;
const int MOD=1000000007;
int T;
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=1LL*res*a%MOD;
        a=1LL*a*a%MOD,b>>=1;
    }
    return res;
}
int getinv(int x)
{
    return ksm(x,MOD-2);
}
int f[N][N];
void init(int n=200)
{
    for(int i=1;i<=n;i++)
        f[0][i]=1,f[i][0]=0;
    int inv2=getinv(2);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=1LL*(f[i-1][j]+f[i][j-1])*inv2%MOD;
    return;
}
int n;
vector<int>G[N];
int fa[N][20],dep[N];
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    fa[u][0]=father;
    for(int i=1;(1<<i)<=n;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
    }
    return;
}
int LCA(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=log2(n);i>=0;i--)
        if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
    if(u==v) return u;
    for(int i=log2(n);i>=0;i--)
        if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
int main()
{
    init();
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    int ans=0;
    int invn=getinv(n);
    for(int p=1;p<=n;p++)
    {
        dfs(p,0);
        int sum=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<i;j++)
            {
                int d=LCA(i,j);
                if(d==i) sum=(sum+1)%MOD;
                else if(d==j) ;
                else sum=(sum+f[dep[i]-dep[d]][dep[j]-dep[d]])%MOD;
            }
        ans=(ans+1LL*sum*invn)%MOD;
    }
    printf("%d",ans);
    return 0;
}