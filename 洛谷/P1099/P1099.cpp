#include<iostream>
#include<cstdio>
using namespace std;
const int INF=1061109567;
const int N=200005;
int n,s;
int top,k;
int ans=INF;
struct Edge
{
	int to,val,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int fa[N];
bool vis[N];
int dis[N];
void dfs(int u,int father)
{
    fa[u]=father;
    if(dis[u]>dis[k]) k=u;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        if(vis[v]) continue;
        dis[v]=dis[u]+edge[i].val;
        dfs(v,u);
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
	dis[1]=0;
    dfs(1,0);
	dis[k]=0;
    dfs(k,0);
	top=k;
	for(int i=top,j=top;i;i=fa[i])
    {
		while(dis[j]-dis[i]>s) j=fa[j];
		ans=min(ans,max(dis[top]-dis[j],dis[i]));
	}
	for(int i=top;i;i=fa[i])
        vis[i]=true;
	for(int i=top;i;i=fa[i])
    {
		k=i,dis[i]=0;
		dfs(i,fa[i]);
	}
    for(int i=1;i<=n;i++)
		ans=max(ans,dis[i]);
	printf("%d",ans);
	return 0;
}