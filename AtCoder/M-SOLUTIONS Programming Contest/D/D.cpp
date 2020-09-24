#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=10005;
int n;
int c[N];
int d[N],tot;
vector<int>G[N];
void dfs(int u,int father)
{
	for(int v:G[u])
	{
		if(v==father) continue;
		dfs(v,u);
	}
	d[u]=c[++tot];
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	sort(c+1,c+n+1);
	dfs(1,0);
	int sum=0;
	for(int i=1;i<n;i++)
		sum+=c[i];
	printf("%d\n",sum);
	for(int i=1;i<=n;i++)
		printf("%d ",d[i]);
	return 0;
}
