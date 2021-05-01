#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200005;
const int MOD=998244353;
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
int n,k;
int p[N];
int c[N],invc[N];
void init(int n=200000)
{
    int q=1LL*(k-1)*getinv(k)%MOD,invq=getinv(q);
    c[0]=invc[0]=1;
    for(int i=1;i<=n;i++)
        c[i]=1LL*c[i-1]*q%MOD,invc[i]=1LL*invc[i-1]*invq%MOD;
    return;
}
struct Binary_Indexed_Tree
{
    int C[N];
    Binary_Indexed_Tree()
    {
        memset(C,0,sizeof(C));
        return;
    }
    void clear()
    {
        memset(C,0,sizeof(C));
        return;
    }
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int y)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            C[i]=(C[i]+y)%MOD;
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res=(res+C[i])%MOD;
        return res;
    }
    int query(int l,int r)
    {
        return ((long long)getsum(r)-getsum(l-1)+MOD)%MOD;
    }
}T,Tp;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    init();
    Tp.clear();
    int inv2=getinv(2);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int f=max(i-k,0);
        ans=(ans+1LL*c[f]*Tp.query(1,p[i]-1)%MOD*inv2%MOD+(T.query(p[i]+1,n)-1LL*c[f]*Tp.query(p[i]+1,n)%MOD*inv2%MOD+MOD)%MOD)%MOD;
        Tp.add(p[i],invc[f]);
        T.add(p[i],1);
    }
    printf("%d",ans);
    return 0;
}