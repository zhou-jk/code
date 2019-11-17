#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
inline int read()
{
    char ch;
    int ret=0;
    bool flag=true;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') flag=false;
    while(ch>='0'&&ch<='9')
        ret=(ret<<1)+(ret<<3)+(ch^48),ch=getchar();
    return flag?ret:-ret;
}
const int N=1000001;
const long long MOD=1ll<<32;
int n,m,q,type;
int pre[N],f[N][21];
bool query(int l,int r)
{
	int u=pre[r];
	if(u<l) return false;
    for(int i=log2(n);i>=0;i--)
	    if(f[u][i]>=l) u=f[u][i];
	return u==l;
}
namespace Get
{
    int A,B,C,P;
    inline void init(){A=read(),B=read(),C=read();P=read();}
    inline int rnd(){return A=(A*B+C)%P;}
}
int main()
{
	n=read(),m=read(),q=read(),type=read();
    for(int i=1;i<=n;i++)
	    pre[i]=((read()&1)?i:pre[i-1]);
    for(int i=m+2;i<=n;i++)
	    f[i][0]=pre[i-m-1];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i<=n;i++)
	        f[i][j]=f[f[i][j-1]][j-1];
    long long ans=0;
    if(type==1) Get::init();
    for(long long i=1;i<=q;i++)
    {
        int l,r;
        if(type==0) l=read(),r=read();
        else l=Get::rnd()%n+1,r=Get::rnd()%n+1;
        if(l>r) swap(l,r);
        if(!query(l,r)) ans=(ans+i*i%MOD)%MOD;
	}
    printf("%lld",ans);
    return 0;
}