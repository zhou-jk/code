#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=200005;
const int MOD=998244353;
int n;
int a[N];
long long solve(int T)
{
	static int p[N],q[N];
	for(int i=1;i<=T/2;i++)
		p[i]=a[i],q[i]=a[i]^1;
	static int b[N];
	for(int i=1;i<=n*2;)
	{
		for(int j=1;j<=T/2;j++)
			b[i+j-1]=p[j];
		i+=T/2;
		for(int j=1;j<=T/2;j++)
			b[i+j-1]=q[j];
		i+=T/2;
	}
	long long ans=0;
	for(int i=1;i<=T/2;i++)
		ans=(ans*2+a[i])%MOD;
	ans=(ans+1)%MOD;
	for(int i=1;i<=n;i++)
		if(b[i]<a[i]) break;
		else if(b[i]>a[i])
		{
			ans=(ans-1+MOD)%MOD;
			break;
		}
	return ans;
}
long long f[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%1d",&a[i]);
	for(int i=1;i<=n*2;i++)
		if(n*2%i==0&&n%i!=0) f[i]=solve(i);
	for(int i=1;i<=n*2;i++)
		if(n*2%i==0&&n%i!=0)
			for(int j=i+i;j<=n*2;j+=i)
				if(n*2%j==0&&n%j!=0) f[j]=(f[j]-f[i]+MOD)%MOD;
	long long ans=0;
	for(int i=1;i<=n*2;i++)
		if(n*2%i==0&&n%i!=0) ans=(ans+f[i]*i%MOD)%MOD;
	printf("%lld",ans);
	return 0;
}
