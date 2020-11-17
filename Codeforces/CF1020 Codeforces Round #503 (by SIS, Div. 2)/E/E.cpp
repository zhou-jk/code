#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=1000005;
int n,m;
vector<int>G[N],G2[N];
bool vis[N],book[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].emplace_back(y);
	}
	memset(vis,true,sizeof(vis));
	for(int u=1;u<=n;u++)
		if(vis[u])
		{
			book[u]=true;
			for(int v:G[u])
				vis[v]=false;
		}
	for(int u=n;u>=1;u--)
		if(book[u])
		{
			for(int v:G[u])
				book[v]=false;
		}
	int k=0;
	for(int i=1;i<=n;i++)
		if(book[i]) k++;
	printf("%d\n",k);
	for(int i=1;i<=n;i++)
		if(book[i]) printf("%d ",i);
	return 0;
}
