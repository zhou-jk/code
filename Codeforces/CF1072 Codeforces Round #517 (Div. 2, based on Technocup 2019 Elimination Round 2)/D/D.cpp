#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=2005;
const int dir[2][2]={{1,0},{0,1}};
int n,k;
char s[N][N];
int f[N][N];
queue<pair<int,int>>q;
bool vis[N][N];
void solve()
{
	vector<pair<int,int>>nxt;
	char c='z';
	while(!q.empty())
	{
		auto [x,y]=q.front();
		q.pop();
		for(int i=0;i<2;i++)
		{
			int tx=x+dir[i][0],ty=y+dir[i][1];
			if(tx<1||tx>n||ty<1||ty>n) continue;
			if(tx==n&&ty==n)
			{
				printf("%c",s[tx][ty]);
				exit(0);
			}
			if(vis[tx][ty]) continue;
			c=min(c,s[tx][ty]);
			vis[tx][ty]=true;
			nxt.emplace_back(tx,ty);
		}
	}
	printf("%c",c);
	for(auto [x,y]:nxt)
	{
		if(s[x][y]==c) q.emplace(x,y);
		vis[x][y]=false;
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	if(k==0)
	{
		if(n==1)
		{
			printf("%c",s[1][1]);
			return 0;
		}
		q.emplace(1,1);
		printf("%c",s[1][1]);
		while(true)
			solve();
		return 0;
	}
	memset(f,63,sizeof(f));
	f[1][1]=0;
	int m=0;
	vector<pair<int,int>>nxt;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i-1>=1) f[i][j]=min(f[i][j],f[i-1][j]);
			if(j-1>=1) f[i][j]=min(f[i][j],f[i][j-1]);
			if(s[i][j]!='a') f[i][j]++;
			if(f[i][j]==k) m=max(m,i+j-1),nxt.emplace_back(i,j);
		}
	if(f[n][n]<=k)
	{
		for(int i=1;i<=2*n-1;i++)
			printf("a");
		return 0;
	}
	for(auto [x,y]:nxt)
		if(x+y-1==m) q.emplace(x,y);
	for(int i=1;i<=m;i++)
		printf("a");
	while(true)
		solve();
	return 0;
}
