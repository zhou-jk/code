#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=505;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n;
int p[N*N];
pair<int,int> pos[N*N];
int dis[N][N];
bool vis[N][N];
void dfs(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		int tx=x+dir[i][0],ty=y+dir[i][1];
		if(tx<0||tx>n||ty<0||ty>n) continue;
		int d=dis[x][y];
		if(!vis[tx][ty]) d++;
		if(dis[tx][ty]>d)
		{
			dis[tx][ty]=d;
			dfs(tx,ty);
		}
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*n;i++)
	{
		scanf("%d",&p[i]);
		pos[i]=make_pair((p[i]-1)/n+1,p[i]%n==0?n:p[i]%n);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=min({j-1,n-j,i-1,n-i});
	long long ans=0;
	for(int i=1;i<=n*n;i++)
	{
		int x=pos[i].first,y=pos[i].second;
		vis[x][y]=true;
		ans+=dis[x][y];
		dis[x][y]--;
		for(int i=0;i<4;i++)
		{
			int tx=x+dir[i][0],ty=y+dir[i][1];
			dis[x][y]=min(dis[x][y],dis[tx][ty]);
		}
		dfs(x,y);
	}
	printf("%lld",ans);
	return 0;
}
