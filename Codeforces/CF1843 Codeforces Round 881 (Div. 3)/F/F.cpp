#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int N=200005;
int n,q;
int a[N];
int dep[N],fa[N][22];
struct Data
{
    int sum,premx,sufmx,premn,sufmn,mx,mn;
    friend Data operator + (const Data &a,const Data &b)
    {
        Data c;
        c.sum=a.sum+b.sum;
        c.premx=max(a.premx,a.sum+b.premx),c.sufmx=max(b.sufmx,b.sum+a.sufmx);
        c.premn=min(a.premn,a.sum+b.premn),c.sufmn=min(b.sufmn,b.sum+a.sufmn);
        c.mn=min(min(a.mn,b.mn),a.sufmn+b.premn),c.mx=max(max(a.mx,b.mx),a.sufmx+b.premx);
        return c;
    }
}f[N][22];
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
Data query(int u,int v)
{
    int w=LCA(u,v);
    Data l=(Data){0,0,0,0,0,0,0},r=(Data){0,0,0,0,0,0,0};
    for(int i=log2(n);i>=0;i--)
        if(fa[u][i]&&dep[fa[u][i]]>=dep[w]) l=l+f[u][i],u=fa[u][i];
    for(int i=log2(n);i>=0;i--)
        if(fa[v][i]&&dep[fa[v][i]]>=dep[w]) r=r+f[v][i],v=fa[v][i];
    swap(r.premn,r.sufmn),swap(r.premx,r.sufmx);
    Data res=l+f[w][0]+r;
    return res;
}
void solve()
{
    scanf("%d",&q);
    fa[1][0]=0,dep[1]=1,a[1]=1;
    f[1][0]=(Data){1,1,1,0,0,1,0};
    n=1;
    while(q--)
    {
        char ch;
        for(ch=getchar();ch!='+'&&ch!='?';ch=getchar());
        if(ch=='+')
        {
            n++;
            int v,x;
            scanf("%d%d",&v,&x);
            fa[n][0]=v,dep[n]=dep[v]+1,a[n]=x;
            for(int i=1;(1<<i)<=n;i++)
                fa[n][i]=fa[fa[n][i-1]][i-1];
            f[n][0]=(Data){a[n],max(a[n],0),max(a[n],0),min(a[n],0),min(a[n],0),max(a[n],0),min(a[n],0)};
            for(int i=1;(1<<i)<=n;i++)
                f[n][i]=f[n][i-1]+f[fa[n][i-1]][i-1];
        }
        else if(ch=='?')
        {
            int u,v,k;
            scanf("%d%d%d",&u,&v,&k);
            Data res=query(u,v);
            if(k>=res.mn&&k<=res.mx) printf("YES\n");
            else printf("NO\n");
        }
    }
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