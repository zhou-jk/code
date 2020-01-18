#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5005;
int n;
int a[N];
int solve(int l,int r,int now)
{
	if(l==r) return 1;
	int high=*min_element(a+l,a+r+1);
	int ans=high-now;
	for(int i=l;i<=r;i++)
		if(a[i]!=high)
		{
			int j;
			for(j=i;j<=r&&a[j+1]>high;j++);
			ans+=solve(i,j,high);
			i=j+1;
		}
	return min(ans,r-l+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("%d",solve(1,n,0));
	return 0;
}
