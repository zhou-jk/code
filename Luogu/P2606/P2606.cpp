#include<iostream>
#include<cstdio>
using namespace std;
const int N=2000001;
long long f[N];
int size[N];
long long fac[N],inv[N];
int n,p;
long long ksm(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%p;
        a=a*a%p,b>>=1;
    }
    return res;
}
void init()
{
    fac[0]=1;
    for (int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%p;
    inv[n]=ksm(fac[n],p-2);
    for(int i=n-1;i>=0;i--)
        inv[i]=(inv[i+1]*(i+1))%p;
    return;
}
long long C(int n,int m)
{
    return fac[n]*inv[m]%p*inv[n-m]%p;
}
long long lucas(int n,int m)
{
    if(m==0) return 1;
    if(n<m) return 0;
    return C(n%p,m%p)*lucas(n/p,m/p);
}
void dfs(int u)
{
    int ls=u*2,rs=u*2+1;
    size[u]=1;
    if(ls<=n) dfs(ls);
    if(rs<=n) dfs(rs);
    size[u]=size[ls]+size[rs]+1;
    if(ls>n)
    {
        f[u]=1;
        return;
    }
    else if(rs>n)
    {
        f[u]=f[ls];
        return;
    }
    f[u]=f[ls]*f[rs]%p*lucas(size[u]-1,size[ls])%p;
    return;
}
int main()
{
    scanf("%d%d",&n,&p);
    init();
    dfs(1);
    printf("%lld",f[1]);
    return 0;
}