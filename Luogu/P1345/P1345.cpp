#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=1061109567;
int n,m,s,t;
int head[2001],cnt=1;
int dis[2001],ans;
queue<int>q;
struct Edge
{
	int to,val,next;
}edge[4001];
void add_edge(int u,int v,int w)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].val=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
	return;
}
void add(int u,int v,int w)
{
	add_edge(u,v,w);
	add_edge(v,u,0);
	return;
}
bool bfs()
{
    memset(dis,-1,sizeof(dis));
    q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v]<0&&edge[i].val>0)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    return dis[t]!=-1;
}
int dfs(int u,int flow)
{
    int now,v,i,sum=0;
    if(u==t) return flow;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
		if(edge[i].val<=0||flow<=sum||dis[v]!=dis[u]+1) continue;
		int now=now=dfs(v,min(flow-sum,edge[i].val));
        edge[i].val-=now;
		edge[i^1].val+=now;
        sum+=now;
    }
    if(sum==0) dis[u]=-1;
    return sum;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);s+=n;
	for(int i=1;i<=n;i++)
    	add(i,i+n,1);
	for(int i=1;i<=m;i++)
    {
		int x,y;
        scanf("%d%d",&x,&y);
        add(x+n,y,INF),add(y+n,x,INF);
    }
    while(bfs())
		ans+=dfs(s,INF);
    printf("%d",ans);
    return 0;
}