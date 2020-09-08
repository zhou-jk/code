#include<iostream>
#include<cstdio>
using namespace std;
const int N=10000005,M=5005;
const int MOD=1000000007;
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
void init(int n=10000000)
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
	scanf("%d%d",&n,&m);
	init();
	long long ans=0;
	for(int i=1;i<=m+1;i++)
		for(int j=0;j<i;j++)
		{
			int a=i-1-j,b=n-m,c=max(m-i,0);
			long long res=C(i-1,j);
			res=(res*fac[a])%MOD;
			res=(res*fac[a+b-1]%MOD*inv[a-1]%MOD)%MOD;
			res=(res*fac[a+b+c]%MOD*inv[a+b]%MOD)%MOD;
			if(j&1) ans=(ans-res+MOD)%MOD;
			else ans=(ans+res)%MOD;
		}
	printf("%lld",ans);
	return 0;
}
