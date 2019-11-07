#include<iostream>
#include<cstdio>
using namespace std;
const int N=200001;
int n,k;
long long ans;
struct Edge
{
	int to,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int dis[N];
void dfs(int u,int father)
{
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs(v,u);
        dis[u]+=dis[v];
    }
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        ans+=min(dis[v],k*2-dis[v]);
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k*2;i++)
    {
        int x;
        scanf("%d",&x);
        dis[x]=1;
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}