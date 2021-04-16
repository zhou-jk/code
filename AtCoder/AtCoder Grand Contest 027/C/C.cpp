#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=200005;
int n,m;
char s[N];
vector<int>G[N];
int dega[N],degb[N];
bool vis[N];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].emplace_back(y);
		G[y].emplace_back(x);
	}
	for(int u=1;u<=n;u++)
		for(int v:G[u])
			if(s[v]=='A') dega[u]++;
			else if(s[v]=='B') degb[u]++;
	queue<int>q;
	for(int u=1;u<=n;u++)
		if(dega[u]==0||degb[u]==0) q.emplace(u);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int v:G[u])
		{
			if(s[u]=='A') dega[v]--;
			else if(s[u]=='B') degb[v]--;
			if(dega[v]==0||degb[v]==0) q.emplace(v);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(!vis[i]) cnt++;
	if(cnt>0) printf("Yes");
	else printf("No");
	return 0;
}