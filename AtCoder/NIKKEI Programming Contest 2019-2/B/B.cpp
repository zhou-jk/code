#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
const int MOD=998244353;
int n;
int d[N];
int cnt[N];
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
	{
		scanf("%d",&d[i]);
		cnt[d[i]]++;
	}
	if(cnt[0]!=1||d[1]!=0)
	{
		printf("0");
		return 0;
	}
	long long ans=1;
	for(int i=1;i<=n-1;i++)
	{
		if(cnt[i]&&!cnt[i-1])
		{
			printf("0");
			return 0;
		}
		ans=ans*ksm(cnt[i-1],cnt[i])%MOD;
	}
	printf("%lld",ans);
	return 0;
}
