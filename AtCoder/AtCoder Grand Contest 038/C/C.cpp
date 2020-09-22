#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1000005;
const int MOD=998244353;
int n,m;
int a[N];
long long c[N];
long long f[N];
int mu[N];
int prime[N],tot;
bool isprime[N];
void init(int n=1000000)
{
	for(int i=1;i<=n;i++)
		isprime[i]=true;
	isprime[1]=false;
	mu[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(isprime[i]) prime[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
			{
				mu[i*prime[j]]=0;
				break;
			}
			mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1;i<=n;i++)
		c[a[i]]=(c[a[i]]+a[i])%MOD;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			f[i]=(f[i]+c[j])%MOD;
	return;
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
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	init();
	m=1000000;
	long long ans=0;
	for(int d=1;d<=m;d++)
	{
		long long id=ksm(d,MOD-2);
		for(int t=1;t<=m/d;t++)
			ans=(ans+(id*mu[t]+MOD)*f[t*d]%MOD*f[t*d]%MOD)%MOD;
	}
	for(int i=1;i<=n;i++)
		ans=(ans-a[i]+MOD)%MOD;
	ans=ans*ksm(2,MOD-2)%MOD;
	printf("%lld",ans);
	return 0;
}
