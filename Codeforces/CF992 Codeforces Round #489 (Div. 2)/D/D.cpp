#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
const long long INF=2e18;
int n,k;
int a[N];
int ad[N],mu[N];
int m;
long long mul(long long a,long long b)
{
	__int128 c=(__int128)a*b;
	if(c>INF) return INF+1;
	else return c;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1,j=1;i<=n;i=j)
	{
		while(j<=n&&a[i]==a[j]) j++;
		if(a[i]==1) m++,ad[m]=j-i,mu[m]=1;
		else
		{
			for(int k=i;k<j;k++)
				m++,ad[m]=mu[m]=a[k];
		}
	}
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		long long fac=1,sum=0;
		for(int j=i;j<=m;j++)
		{
			fac=mul(fac,mu[j]),sum+=ad[j];
			if(fac>INF) break;
			if(fac%k!=0) continue;
			if(fac/k==sum) ans++;
			else
			{
				long long num=fac/k;
				int t=0,c=0;
				if(mu[i]==1) t+=ad[i]-1,c+=ad[i];
				if(mu[j]==1) t+=ad[j]-1,c+=ad[j];
				if(sum-t<=num&&num<=sum)
				{
					if(mu[i]==1&&mu[j]==1)
					{
						int s=num-(sum-c);
						int l=max(ad[i]-(s-1)+1,1),r=min(ad[i],ad[i]-1-(s-1-ad[j])+1);
						ans+=r-l+1;
					}
					else ans++;
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
