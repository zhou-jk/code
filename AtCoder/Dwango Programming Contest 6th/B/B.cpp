#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
const int MOD=1000000007;
int n;
int x[N];
long long inv[N];
void init(int n=100000)
{
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	return;
}
long long f[N];
int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]+inv[i];
	long long ans=0;
	for(int i=1;i<n;i++)
		ans=(ans+(x[i+1]-x[i])*f[i]%MOD)%MOD;
	for(int i=1;i<n;i++)
		ans=ans*i%MOD;
	printf("%lld",ans);
	return 0;
}
