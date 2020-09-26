#include<iostream>
#include<cstdio>
#include<tuple>
using namespace std;
const int N=25;
const int MOD=1000000007;
int n,m;
int x[N*N],y[N*N];
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
long long fac[N*N],inv[N*N];
void init(int n=400)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[n]=ksm(fac[n],MOD-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%MOD;
	return;
}
struct Union_Set
{
	int fa[N];
	void init()
	{
		for(int i=0;i<n;i++)
			fa[i]=i;
		return;
	}
	int getf(int v)
	{
		if(v==fa[v]) return v;
		fa[v]=getf(fa[v]);
		return fa[v];
	}
	void merge(int u,int v)
	{
		int f1=getf(u),f2=getf(v);
		if(f1!=f2) fa[f2]=f1;
		return;
	}
};
tuple<int,int,long long,long long> f[1<<N]; 
int main()
{
	init();
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		x[i]--,y[i]--;
	}
	for(int S=0;S<(1<<(n-1));S++)
	{
		Union_Set D;
		D.init();
		int b=n-1,num=m;
		for(int i=0;i<n-1;i++)
			if(S&(1<<i))
			{
				D.merge(x[i],y[i]);
				b--,num--;
			}
		for(int i=n-1;i<m;i++)
			if(D.getf(x[i])==D.getf(y[i])) num--;
		f[S]=make_tuple(num,b,0,0);
	}
	f[(1<<(n-1))-1]=make_tuple(0,0,1,0);
	for(int S=(1<<(n-1))-1-1;S>=0;S--)
		for(int i=0;i<n-1;i++)
			if(!(S&(1<<i)))
			{
				int T=S|(1<<i);
				int &n=get<0>(f[T]),&sn=get<0>(f[S]);
				int k=sn-n-1;
				long long &c=get<2>(f[T]),&sc=get<2>(f[S]);
				sc=(sc+fac[n+k]*inv[n]%MOD*c%MOD)%MOD;
				int &sb=get<1>(f[S]);
				long long &s=get<3>(f[T]),&st=get<3>(f[S]);
				st=((st+fac[n+k+1]%MOD*inv[n+1]%MOD*s%MOD)%MOD+sb*fac[n+k]%MOD*inv[n]%MOD*c%MOD)%MOD;
			}
	printf("%lld",get<3>(f[0]));
	return 0;
}

