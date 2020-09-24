#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5005;
int n;
int a[4],b[4];
long long f[N*N];
int main()
{
	scanf("%d",&n);
	scanf("%d%d%d",&a[1],&a[2],&a[3]);
	scanf("%d%d%d",&b[1],&b[2],&b[3]);
	for(int i=1;i<=3;i++)
		if(b[i]>a[i])
		{
			for(int j=a[i];j<=n;j++)
				f[j]=max(f[j],f[j-a[i]]+b[i]);
		}
	long long ans=0;
	for(int j=0;j<=n;j++)
		ans=max(ans,f[j]+n-j);
	n=ans;
	memset(f,0,sizeof(f));
	for(int i=1;i<=3;i++)
		if(a[i]>b[i])
		{
			for(int j=b[i];j<=n;j++)
				f[j]=max(f[j],f[j-b[i]]+a[i]);
		}
	ans=0;
	for(int j=0;j<=n;j++)
		ans=max(ans,f[j]+n-j);
	printf("%lld",ans);
	return 0;
}
