#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=1005;
const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m;
char s[N][N];
int id[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	memset(id,63,sizeof(id));
	queue<pair<int,int> >q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='#')
			{
				id[i][j]=0;
				q.push(make_pair(i,j));
			}
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int tx=x+dir[i][0],ty=y+dir[i][1];
			if(tx<1||tx>n||ty<1||ty>m) continue;
			if(id[tx][ty]>id[x][y]+1)
			{
				id[tx][ty]=id[x][y]+1;
				q.push(make_pair(tx,ty));
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans=max(ans,id[i][j]);
	printf("%d",ans);
	return 0;
}
