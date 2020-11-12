#include<iostream>
#include<cstdio>
using namespace std;
const int N=55;
int n,m;
int a[N][N],b[N][N];
int c[N][N],d[N][N];
bool check(int s[N][N])
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]<=s[i-1][j]||s[i][j]<=s[i][j-1]) return false;
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&b[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			c[i][j]=min(a[i][j],b[i][j]),d[i][j]=max(a[i][j],b[i][j]);
	if(check(c)&&check(d)) printf("Possible");
	else printf("Impossible");
	return 0;
}
