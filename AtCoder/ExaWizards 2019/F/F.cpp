#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n,m,Q;
char s[N],t[N];
int pw[N],pe[N],nw[N],ne[N];
int pn[N],ps[N],nn[N],ns[N];
int a,b,c,d;
vector<pair<int,int> >G[N];
int dijkstra(int s,int t,int n)
{
	static int dis[N];
	static bool vis[N];
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	for(int i=0;i<n;i++)
		dis[i]=INF,vis[i]=false;
	dis[s]=0;
	q.push(make_pair(dis[s],s));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(auto [v,w]:G[u])
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push(make_pair(dis[v],v));
			}
	}
	if(dis[t]>=INF) return -1;
	else return dis[t];
}
int id[N];
void solve()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	vector<int>posr={pw[a],pe[a],a,nw[a],ne[a],pw[c],pe[c],c,nw[c],ne[c]},posc={pn[b],ps[b],b,nn[b],ns[b],pn[d],ps[d],d,nn[d],ns[d]};
	sort(posr.begin(),posr.end());
	posr.erase(unique(posr.begin(),posr.end()),posr.end());
	sort(posc.begin(),posc.end());
	posc.erase(unique(posc.begin(),posc.end()),posc.end());
	vector<pair<int,int> >p;
	int S=0,T=0;
	for(int x:posr)
		for(int y:posc)
		{
			if(x==0||y==0) continue;
			p.push_back(make_pair(x,y));
			if(x==a&&y==b) S=p.size()-1;
			if(x==c&&y==d) T=p.size()-1;
		}
	int tot=p.size();
	for(int i=0;i<tot;i++)
		id[i]=i;
	sort(id,id+tot,[=](const int &i,const int &j){return p[i].first==p[j].first?p[i].second<p[j].second:p[i].first<p[j].first;});
	for(int i=0;i<tot-1;i++)
	{
		int j=i+1;
		int sx=p[id[i]].first,sy=p[id[i]].second;
		int tx=p[id[j]].first,ty=p[id[j]].second;
		if(sx==tx)
		{
			if(s[sx]=='E') G[id[i]].push_back(make_pair(id[j],ty-sy));
			else if(s[sx]=='W') G[id[j]].push_back(make_pair(id[i],ty-sy));
		}
	}
	sort(id,id+tot,[=](const int &i,const int &j){return p[i].second==p[j].second?p[i].first<p[j].first:p[i].second<p[j].second;});
	for(int i=0;i<tot-1;i++)
	{
		int j=i+1;
		int sx=p[id[i]].first,sy=p[id[i]].second;
		int tx=p[id[j]].first,ty=p[id[j]].second;
		if(sy==ty)
		{
			if(t[sy]=='S') G[id[i]].push_back(make_pair(id[j],tx-sx));
			else if(t[sy]=='N') G[id[j]].push_back(make_pair(id[i],tx-sx));
		}
	}
	int ans=dijkstra(S,T,tot);
	printf("%d\n",ans);
	for(int i=0;i<tot;i++)
		G[i].clear();
	return;
}
int main()
{
	scanf("%d%d%d",&n,&m,&Q);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		pw[i]=pw[i-1],pe[i]=pe[i-1];
		if(s[i]=='W') pw[i]=i;
		if(s[i]=='E') pe[i]=i;
	}
	for(int i=n;i>=1;i--)
	{
		nw[i]=nw[i+1],ne[i]=ne[i+1];
		if(s[i]=='W') nw[i]=i;
		if(s[i]=='E') ne[i]=i;
	}
	scanf("%s",t+1);
	for(int i=1;i<=m;i++)
	{
		pn[i]=pn[i-1],ps[i]=ps[i-1];
		if(t[i]=='N') pn[i]=i;
		if(t[i]=='S') ps[i]=i;
	}
	for(int i=m;i>=1;i--)
	{
		nn[i]=nn[i+1],ns[i]=ns[i+1];
		if(t[i]=='N') nn[i]=i;
		if(t[i]=='S') ns[i]=i;
	}
	while(Q--)
		solve();
	return 0;
}
