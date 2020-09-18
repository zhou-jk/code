#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=205;
int n;
int a[N][N];
int col[N];
void dfs(int u,int color)
{
	if(col[u]!=-1)
	{
		if(col[u]!=color)
		{
			printf("-1");
			exit(0);
		}
		return;
	}
	col[u]=color;
	for(int v=1;v<=n;v++)
		if(a[u][v]) dfs(v,color^1);
	return;
}
int f[N][N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%1d",&a[i][j]);
	memset(col,-1,sizeof(col));
	dfs(1,0);
	memset(f,63,sizeof(f));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]) f[i][j]=a[i][j];
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans=max(ans,f[i][j]+1);
	printf("%d",ans);
	return 0;
}
