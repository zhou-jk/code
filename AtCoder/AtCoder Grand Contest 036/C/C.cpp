#include<iostream>
#include<cstdio>
using namespace std;
const int N=4000005;
const int MOD=998244353;
int n,m;
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
long long fac[N],inv[N];
void init(int n=4000000)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[n]=ksm(fac[n],MOD-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%MOD;
	return;
}
long long C(int n,int m)
{
	if(m>n) return 0;
	else return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int main()
{
	init();
	scanf("%d%d",&n,&m);
	long long ans=0;
	int num=(m+1)%2==1?m+1:m+2;
	for(int i=0;i<=n&&i<=m;i++)
	{
		if(i%2!=m%2) continue;
		int t=(3*m-i)/2;
		if(t<0) continue; 
		long long res=0;
		res=(res+C(t+n-1,n-1)*C(n,i)%MOD)%MOD;
		if(t-m>=0) res=(res-C(t-m+n-1,n-1)*C(n-1,i-1)%MOD*n%MOD+MOD)%MOD;
		if(t-(m+1)>=0) res=(res-C(t-(m+1)+n-1,n-1)*C(n-1,i)%MOD*n%MOD+MOD)%MOD;
		ans=(ans+res)%MOD;
	}
	printf("%lld",ans);
	return 0;
}
