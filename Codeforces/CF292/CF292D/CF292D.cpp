#include<iostream>
#include<cstdio>
using namespace std;
int n,m,q;
int u[10001],v[10001];
int fl[10002][501], fr[10002][501],f[501];
int getf(int *fa, int v)
{
    if(v==fa[v]) return v;
    fa[v]=getf(fa,fa[v]);
    return fa[v];
}
void merge(int *fa,int u,int v)
{
    int f1=getf(fa,u),f2=getf(fa,v);
    if(f1!=f2) fa[f2]=f1;
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= m; i++)
        scanf("%d%d",&u[i],&v[i]);
    for(int i=1;i<=n;i++)
        fl[0][i]=fr[0][i]=fl[m+1][i]=fr[m+1][i]=i;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            fl[i][j]=fl[i-1][j];
        merge(fl[i],u[i],v[i]);
    }
    for(int i=m;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
            fr[i][j]=fr[i+1][j];
        merge(fr[i],u[i],v[i]);
    }
    scanf("%d",&q);
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        for(int i=1;i<=n;i++)
            f[i]=fl[l-1][i];
        for(int i=1;i<=n;i++)
            merge(f,fl[l-1][i],fr[r+1][i]);
        int ans=0;
        for(int i=1;i<=n;i++)
            if(i==getf(f,i)) ans++;
        printf("%d\n",ans);
    }
    return 0;
}