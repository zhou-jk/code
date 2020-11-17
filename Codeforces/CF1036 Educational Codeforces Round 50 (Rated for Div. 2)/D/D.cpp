#include<iostream>
#include<cstdio>
using namespace std;
const int N=300005;
int n,m;
int a[N],b[N];
long long sa[N],sb[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		sa[i]=sa[i-1]+a[i];
	for(int i=1;i<=m;i++)
		sb[i]=sb[i-1]+b[i];
	if(sa[n]!=sb[m])
	{
		printf("-1");
		return 0;
	}
	int ans=0;
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<=m&&sb[j]<sa[i]) j++;
		if(sb[j]==sa[i]) ans++;
	}
	printf("%d",ans);
	return 0;
}
