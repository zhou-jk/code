#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
using namespace std;
const int N=105,M=25,K=10;
const long long INF=4557430888798830399;
int n,m,R,P;
int pw[K];
int a[N];
int v[M];
long long f[N][N][M][K],g[N][N];
long long dfsg(int l,int r);
long long dfsf(int l,int r,int x,int k)
{
    if(f[l][r][x][k]!=-1) return f[l][r][x][k];
    if(k==1)
    {
        long long res=-INF;
        for(int i=l;i<=r;i++)
            if(a[i]==x) res=max(res,dfsg(l,i-1)+dfsg(i+1,r));
        return f[l][r][x][k]=res;
    }
    else
    {
        long long res=-INF;
        for(int i=l;i<r;i++)
            res=max(res,dfsf(l,i,x,k-1)+dfsf(i+1,r,x,k-1));
        return f[l][r][x][k]=res;
    }
}
long long dfsg(int l,int r)
{
    if(l>r) return 0;
    if(g[l][r]!=-1) return g[l][r]; 
    long long res=-INF;
    for(int i=l;i<r;i++)
        res=max(res,dfsg(l,i)+dfsg(i+1,r));
    for(int x=1;x<=m;x++)
        for(int k=1;k<=R;k++)
            res=max(res,dfsf(l,r,x,k)+pw[k-1]*v[x]);
    return g[l][r]=res;
}
void solve()
{
    cin>>n>>m>>R>>P;
    R=min(R,7);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>v[i];
    pw[0]=1;
    for(int i=1;i<=R;i++)
        pw[i]=pw[i-1]*P;
    for(int l=1;l<=n;l++)
        for(int r=l;r<=n;r++)
            g[l][r]=-1;
    for(int l=1;l<=n;l++)
        for(int r=l;r<=n;r++)
            for(int x=1;x<=m;x++)
                for(int k=1;k<=R;k++)
                    f[l][r][x][k]=-1;
    long long ans=dfsg(1,n);
    cout<<ans<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}