#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=85,M=325;
const int INF=1061109567;
const long long LINF=4557430888798830399;
int n,m;
int x[N],y[N];
long long v[N];
char t[M];
int a[M],b[M];
struct Edge
{
	int to,next;
	long long cost,flow;
}edge[N*N*6];
int head[N*4],cnt=1;
void add_edge(int u,int v,long long c,int f)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	edge[cnt].cost=c;
	edge[cnt].flow=f;
	head[u]=cnt;
	return;
}
void add(int u,int v,long long c,int f)
{
	add_edge(u,v,c,f);
	add_edge(v,u,-c,0);
	return;
}
int S,T;
long long dis[N*4];
bool spfa()
{
	static bool vis[N*4];
	memset(vis,false,sizeof(vis));
	for(int i=0;i<N*4;i++)
		dis[i]=-LINF;
	queue<int>q;
	dis[S]=0;
	vis[S]=true;
	q.push(S);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(edge[i].flow<=0) continue;
			if(dis[v]<dis[u]+edge[i].cost)
			{
				dis[v]=dis[u]+edge[i].cost;
				if(!vis[v])
				{
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
	return dis[T]!=-LINF;
}
bool book[N*4];
int cur[N*4];
pair<long long,long long>dfs(int u,long long flow)
{
    if(u==T||flow==0) return make_pair(flow,0);
    book[u]=true;
    long long used=0,res=0;
    for(int &i=cur[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(book[v]||dis[v]!=dis[u]+edge[i].cost||edge[i].flow<=0) continue;
        pair<long long,long long>t=dfs(v,min(flow,edge[i].flow));
        long long now=t.first;
        res+=t.second+now*edge[i].cost;
        flow-=now;
        edge[i].flow-=now;
        edge[i^1].flow+=now;
        used+=now;
        if(flow==0) break;
    }
    book[u]=false;
    return make_pair(used,res);
}
pair<long long,long long> dinic()
{
    long long ans=0,Min=0;
    while(spfa())
    {
        memcpy(cur,head,sizeof(head));
        pair<long long,long long> res=dfs(S,INF);
        ans+=res.first,Min+=res.second;
    }
    return make_pair(ans,Min);
}
int lr[N],rr[N],lc[N],rc[N];
long long solve(int k)
{
	for(int i=1;i<=m;i++)
		if(t[i]=='L')
		{
			if(b[i]+1<=k) lr[b[i]+1]=max(lr[b[i]+1],a[i]);
		}
		else if(t[i]=='R')
		{
			if(k-b[i]>=1) rr[k-b[i]]=min(rr[k-b[i]],a[i]);
		}
		else if(t[i]=='D')
		{
			if(b[i]+1<=k) lc[b[i]+1]=max(lc[b[i]+1],a[i]);
		}
		else if(t[i]=='U')
		{
			if(k-b[i]>=1) rc[k-b[i]]=min(rc[k-b[i]],a[i]);
		}
	for(int i=2;i<=k;i++)
		lr[i]=max(lr[i],lr[i-1]),lc[i]=max(lc[i],lc[i-1]);
	for(int i=k-1;i>=1;i--)
		rr[i]=min(rr[i],rr[i+1]),rc[i]=min(rc[i],rc[i+1]);
	S=0,T=n+n+k+k+1;
	for(int i=1;i<=n;i++)
		add(i,i+n,v[i],1);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			if(x[j]>lr[i]&&x[j]<rr[i]) add(i+n+n,j,0,1);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			if(y[j]>lc[i]&&y[j]<rc[i]) add(j+n,i+n+n+k,0,1);
	for(int i=1;i<=k;i++)
		add(S,i+n+n,0,1),add(i+n+n+k,T,0,1);
	long long res=dinic().second;
	for(int i=1;i<=k;i++)
		lr[i]=lc[i]=0,rr[i]=rc[i]=INF;
	cnt=1;
	for(int i=0;i<=n+n+k+k+1;i++)
		head[i]=0;
	return res;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i]>>v[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>t[i]>>a[i]>>b[i];
	for(int i=1;i<=n;i++)
		lr[i]=lc[i]=0,rr[i]=rc[i]=INF;
	long long ans=0;
	for(int k=1;k<=n;k++)
		ans=max(ans,solve(k));
	cout<<ans;
	return 0;
}
