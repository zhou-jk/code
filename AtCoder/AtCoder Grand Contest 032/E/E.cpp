#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int n,m;
int a[N];
bool check(int x)
{
	int l=x+1,r=n*2;
	while(l<r)
	{
		if(a[l]+a[r]<m) return false;
		l++,r--;
	}
	return true;
}
int calc(int x)
{
	int ans=0;
	int l=x+1,r=n*2;
	while(l<r)
	{
		ans=max(ans,a[l]+a[r]-m);
		l++,r--;
	}
	l=1,r=x;
	while(l<r)
	{
		ans=max(ans,a[l]+a[r]);
		l++,r--;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*2;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+n+1);
	int L=0;
	int l=0,r=2*n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(mid&1) mid++;
		if(mid>r) break;
		if(check(mid)) L=mid,r=mid-2;
		else l=mid+2;
	}
	printf("%d",calc(L));
	return 0;
}
