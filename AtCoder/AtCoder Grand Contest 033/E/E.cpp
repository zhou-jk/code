#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
const int MOD=1000000007;
int n,m;
char s[N];
long long f[N];
long long sum[N];
long long g[N][2];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	int lim=n;
	bool flag=false;
	for(int i=1,j=1;i<=m;i=j)
	{
		while(j<=m&&s[i]==s[j]) j++;
		int len=j-i;
		if(j<=m)
		{
			if(i==1)
			{
				if(len&1) lim=min(lim,len);
				else lim=min(lim,len+1);
			}
			if(s[i]==s[1]&&len%2==1) lim=min(lim,len);
		}
		else if(i==1) flag=true;
	}
	long long ans=0;
	if(flag)
	{
		f[0]=1,sum[0]=1;
		for(int i=1;i<=n;i++)
		{
			if(i-2>=0) f[i]=sum[i-2];
			sum[i]=(sum[i-1]+f[i])%MOD;
		}
		for(int i=0;i<=n-2;i++)
			ans=(ans+f[i]*(n-i)%MOD)%MOD;
		ans++;
	}
	else
	{
		f[0]=0,g[0][0]=0;
		f[1]=1,g[1][1]=1;
		for(int i=2;i<=n;i++)
		{
			f[i]=(g[i-2][i&1]-(i-1-lim-1>=0?g[i-1-lim-1][i&1]:0)+MOD)%MOD;
			g[i][0]=g[i-1][0],g[i][1]=g[i-1][1];
			g[i][i&1]=(g[i][i&1]+f[i])%MOD;
		}
		for(int i=1;i<=n;i++)
			if(n-i<=lim&&(n-i)%2==1) ans=(ans+f[i]*(n-i+1)%MOD)%MOD;
	}
	printf("%lld",ans);
	return 0;
}
