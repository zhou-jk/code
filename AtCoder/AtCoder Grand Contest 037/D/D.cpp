#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=105;
int n,m;
bool e[N][N];
int match[N];
bool vis[N];
bool dfs(int u)
{
	for(int v=1;v<=n;v++)
		if(e[u][v]&&!vis[v])
		{
			vis[v]=1;
			if(!match[v]||dfs(match[v]))
			{
				match[v]=u;
				return true;
			}
		}
	return false;
}
void KM()
{
	memset(match,0,sizeof(match));
	for(int i=1;i<=n;i++)
	{
		memset(vis,false,sizeof(vis));
		dfs(i);
	}
	return;
}
int a[N][N],b[N][N],id[N][N];
bool book[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			id[i][j]=(a[i][j]-1)/m+1;
		}
	for(int k=1;k<=m;k++)
	{
		memset(e,0,sizeof(e));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(!book[i][j]) e[i][id[i][j]]=1;
		KM();
		for(int j=1;j<=n;j++)
		{
			int u=match[j];
			for(int v=1;v<=m;v++)
				if(!book[u][v]&&id[u][v]==j)
				{
					book[u][v]=true;
					b[u][k]=a[u][v];
					break;
				}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<j;k++)
				if(b[j][i]<b[k][i]) swap(b[j][i],b[k][i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	return 0;
}
