#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
const int MOD=1000000007;
int n,m;
int a[N],b[N];
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
long long f[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	long long inv=ksm(m,MOD-2);
	for(int i=n;i>=1;i--)
	{
		if(a[i]&&b[i]) f[i]=a[i]==b[i]?f[i+1]:a[i]>b[i];
		else if(a[i]) f[i]=(a[i]-1+f[i+1])*inv%MOD;
		else if(b[i]) f[i]=(m-b[i]+f[i+1])*inv%MOD;
		else f[i]=(1LL*m*(m-1)/2%MOD+f[i+1]*m%MOD)*inv%MOD*inv%MOD;
	}
	printf("%lld",f[1]);
	return 0;
}
