#include<iostream>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int N=100005;
int n;
int id[N]; 
long long d[N],dis[N];
int siz[N];
unordered_map<long long,int>vis;
vector<pair<int,int>>G;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&d[i]);
	for(int i=1;i<=n;i++)
		id[i]=i,vis[d[i]]=i,siz[i]=1;
	sort(id+1,id+n+1,[=](const int &x,const int &y){return d[x]>d[y];});
	for(int i=1;i<=n-1;i++) 
	{
		long long nd=d[id[i]]-(n-siz[id[i]])+siz[id[i]];
		if(!vis[nd])
		{
			printf("-1");
			return 0;
		}
		int fa=vis[nd];
		G.emplace_back(id[i],fa);
		siz[fa]+=siz[id[i]];
		dis[fa]+=dis[id[i]]+siz[id[i]];
	}
	if(d[id[n]]!=dis[id[n]])
	{
		printf("-1");
		return 0;
	}
	for(auto [u,v]:G)
		printf("%d %d\n",u,v);
	return 0;
}
