#include<iostream>
#include<cstdio>
using namespace std;
const int N=(1<<20)+5; 
int n,A,B;
int res[N];
void solve(int k,int a,int b,int l,int r)
{
	if(__builtin_popcount(a^b)%2==0)
	{
		printf("NO");
		exit(0);
	}
	if(k==0)
	{
		res[l]=a,res[r]=b;
		return;
	}
	int mid=(l+r)/2;
	int m=(1<<k)-1;
	if((a&(1<<k))==(b&(1<<k)))
	{
		solve(k-1,a&m,b&m,mid+1,r);
		solve(k-1,a&m,res[mid+2],l+1,mid+1);
		if(a&(1<<k))
		{
			for(int i=mid+2;i<=r;i++)
				res[i]|=1<<k;
			res[l]=a;
		}
		else
		{
			for(int i=l+1;i<=mid+1;i++)
				res[i]|=1<<k;
			res[l]=a;
		}
	}
	else
	{
		solve(k-1,a&m,(b&m)^1,l,mid);
		solve(k-1,res[mid],b&m,mid+1,r);
		if(a&(1<<k))
		{
			for(int i=l;i<=mid;i++)
				res[i]|=1<<k;
		}
		else
		{
			for(int i=mid+1;i<=r;i++)
				res[i]|=1<<k;
		}
	}
	return;
}
int main()
{
	scanf("%d%d%d",&n,&A,&B);
	solve(n-1,A,B,0,(1<<n)-1);
	printf("YES\n");
	for(int i=0;i<(1<<n);i++)
		printf("%d ",res[i]);
	return 0;
}
