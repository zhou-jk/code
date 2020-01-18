#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000005;
const int MOD=1000000000; 
int n,m,k;
int x[N],y[N],color[N];
int fa[N<<1],w[N<<1];
int getf(int v)
{
    if(v==fa[v])return v;
    int f=fa[v];
    fa[v]=getf(fa[v]);
    w[v]^=w[f];
    return fa[v];
}
long long ksm(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%MOD;
        a=a*a%MOD,b>>=1;
    }
    return res;
}
long long solve()
{
    memset(w,0,sizeof(w));
    for(int i=n+m+1;i>=1;i--)
        fa[i]=i;
    fa[n+1]=1;
    for(int i=1;i<=k;i++)
    {
        if(x[i]==1&&y[i]==1) continue;
        int tmp;
        if((x[i]&1)||(y[i]&1)) tmp=0;
        else tmp=1;
        tmp^=color[i];
        int f1=getf(x[i]),f2=getf(y[i]+n);
        fa[f2]=f1;
        w[f2]=w[x[i]]^w[y[i]+n]^tmp;
        if(f1==f2&&w[f2]) return 0;
    }
    int cnt=0;
    for(int i=n+m;i>=1;i--)
        if(fa[i]==i) cnt++;
    return ksm(2,cnt-1);
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    int flag=0;
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d%d",&x[i],&y[i],&color[i]);
        if(x[i]==1&&y[i]==1)
        {
            if(!color[i]) flag=1;
            else flag=2;
        }
    }
    long long ans1=solve();
    for(int i=1;i<=k;i++)
        color[i]^=1;
    long long ans2=solve();
    if(flag==1) ans2=0;
    if(flag==2) ans1=0; 
    printf("%lld",(ans1+ans2)%MOD);
    return 0;
}