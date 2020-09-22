#include<iostream>
#include<cstdio>
using namespace std;
const int N=2005;
const int MOD=1000000007;
int n,k;
int a[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	long long ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]>a[j]) ans++;
	ans=ans*k%MOD;
	long long sn=0;
	for(int i=1;i<=n;i++)
	{
		int num=0;
		for(int j=1;j<=n;j++)
			if(a[j]>a[i]) num++;
		sn+=num;
	}
	sn%=MOD;
	long long sk=1LL*(k-1)*k/2%MOD;
	ans=(ans+sn*sk%MOD)%MOD;
	printf("%lld",ans);
	return 0;
}
