#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1005;
const int MOD=1000000007;
int n,m;
int a[N],b[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(a[i]==a[i-1])
		{
			printf("0");
			return 0;
		}
	sort(b+1,b+m+1);
	for(int i=1;i<=m;i++)
		if(b[i]==b[i-1])
		{
			printf("0");
			return 0;
		}
	long long ans=1;
	int i=n,j=m;
	for(int k=n*m;k>=1;k--)
	{
		while(i>=1&&a[i]>=k) i--;
		while(j>=1&&b[j]>=k) j--;
		long long res=1;
		if(a[i+1]==k&&b[j+1]==k) res=1;
		else if(a[i+1]==k&&b[j+1]!=k) res=m-j;
		else if(a[i+1]!=k&&b[j+1]==k) res=n-i;
		else res=(1LL*(n-i)*(m-j)-(1LL*n*m-k))%MOD;
		ans=ans*res%MOD;
	}
	printf("%lld",ans);
	return 0;
}
