#include<iostream>
#include<cstdio>
using namespace std;
const int N=4000001;
const int MOD=998244353;
int n,m;
int f[N];
int getf(int v)
{
    if(v==f[v]) return v;
    f[v]=getf(f[v]);
    return f[v];
}
void merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2) f[f2]=f1;
    return;
}
int ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int op,u,v;
        scanf("%d%d%d",&op,&u,&v);
        if(op==0) merge(u,v);
        else if(op==1) ans=((ans<<1)+(getf(u)==getf(v)))%MOD;
    }
    printf("%d",ans);
    return 0;
}