#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=105;
int T;
int n,m;
int a[N][N];
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if((i+j)%2!=a[i][j]%2) a[i][j]++;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
