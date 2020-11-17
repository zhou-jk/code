#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n,m;
int a[N];
int c[N];
bool check(int x)
{
	int cnt=0;
	for(int i=1;i<=100;i++)
		cnt+=c[i]/x;
	return cnt>=n;
}
int main()
{
	scanf("%d%d",&n,&m);
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		c[a[i]]++;
		r=max(r,c[a[i]]);
	}
	int ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
