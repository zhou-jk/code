#include<iostream>
#include<cstdio>
using namespace std;
const int N=105,M=25,R=25,P=10;
const long long INF=4557430888798830399;
int n,m,r,p;
long long pw[R];
int a[N];
int v[M];
long long f[N][N][M][R];
long long dfs(int l,int r,int k,int o) //[l,r] level k type o
{
    if(f[l][r][k][o]!=-1) return f[l][r][k][o];
    if(k==0)
    {
        if(l==r) return f[l][r][k][o]=v[a[l]];
        else
        {
            for(int kk=1;kk<=r;kk++)
                for(int oo=1;oo<=m;oo++)
                    f[l][r][k][o]=max(f[l][r][k][o],dfs(l,r,kk,oo)+pw[kk-1]*v[oo]);
            return f[l][r][k][o];
        }
    }
    if(l==r)
    {
        if(k!=1||o!=a[l]) return f[l][r][k][o]=-INF;
        else return f[l][r][k][o]=0;
    }
    long long res=-INF;
    for(int i=l;i<r;i++)
        res=max(res,max(dfs(l,i,0,o)+dfs(i+1,r,k,o),dfs(l,i,k,o)+dfs(i+1,r,0,o)));
    if(k>1)
    {
        for(int i=l;i<r;i++)
            res=max(res,dfs(l,i,k-1,o)+dfs(i+1,r,k-1,o));
    }
    if(res>=0) cerr<<"find"<<l<<" "<<r<<" k:"<<k<<" "<<o<<" "<<res<<"\n";
    return f[l][r][k][o]=res;
}
void solve()
{
    scanf("%d%d%d%d",&n,&m,&r,&p);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&v[i]);
    pw[0]=1;
    for(int i=1;i<=r;i++)
        pw[i]=pw[i-1]*p;
    for(int l=1;l<=n;l++)
        for(int r=1;r<=n;r++)
            for(int k=0;k<=r;k++)
                for(int o=1;o<=m;o++)
                    f[l][r][k][o]=-1;
    long long ans=0;
    for(int o=1;o<=m;o++)
        ans=max(ans,dfs(1,n,0,o));
    printf("%lld\n",ans);
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}