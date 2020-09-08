#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005;
int n;
int a[N];
long long f[N],g[N];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		scanf("%d",&a[i]);
	if(a[0]>1)
	{
		printf("-1");
		return 0;
	}
	g[n]=a[n];
	for(int i=n-1;i>=0;i--)
		g[i]=g[i+1]+a[i];
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=min((f[i-1]-a[i-1])*2,g[i]);
		if(a[i]>f[i])
		{
			printf("-1");
			return 0;
		}
	}
	long long ans=0;
	for(int i=0;i<=n;i++)
		ans+=f[i];
	printf("%lld",ans);
	return 0;
}

