#include<iostream>
#include<cstdio>
using namespace std;
const int N=505;
int n;
int e[N][N];
void solve(int l,int r,int dep)
{
	if(l==r) return;
	int mid=(l+r)/2;
	for(int i=l;i<=mid;i++)
		for(int j=mid+1;j<=r;j++)
			e[i][j]=e[j][i]=dep;
	solve(l,mid,dep+1);
	solve(mid+1,r,dep+1);
	return;
}
int main()
{
	scanf("%d",&n);
	solve(1,n,1);
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
			printf("%d ",e[i][j]);
		printf("\n");
	}
	return 0;
}
