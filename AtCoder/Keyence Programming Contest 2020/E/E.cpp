#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m;
int d[N];
int id[N];
vector<pair<int,int> >G[N];
int col[N];
int ans[N<<1];
void draw(int u)
{
	if(col[u]) return;
	for(auto [v,i]:G[u])
		if(col[v]==0&&d[u]==d[v])
		{
			col[u]=1,col[v]=2;
			ans[i]=d[u];
			return;
		}
	for(auto [v,i]:G[u])
		if(col[v])
		{
			col[u]=col[v]==1?2:1;
			ans[i]=d[u];
			return;
		}
	printf("-1");
	exit(0);
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]),id[i]=i;
	sort(id+1,id+n+1,[=](const int &x,const int &y){return d[x]<d[y];});
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(make_pair(y,i));
		G[y].push_back(make_pair(x,i));
	}
	for(int i=1;i<=n;i++)
		draw(id[i]);
	for(int i=1;i<=m;i++)
		if(!ans[i]) ans[i]=1e9;
	for(int i=1;i<=n;i++)
		if(col[i]==1) printf("W");
		else if(col[i]==2) printf("B");
	printf("\n");
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}
