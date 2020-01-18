#include<iostream>
#include<cstdio>
using namespace std;
const int N=500001;
int n,root;
long long ans;
int dp[N];
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
void dfs(int u,int father)
{
	for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs(v,u);
        dp[u]=max(dp[u],dp[v]+edge[i].val);
    }
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        ans+=dp[u]-dp[v]-edge[i].val;
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&root);
	for(int i=1;i<n;i++)
	{
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,z);
	}
	dfs(root,0);
	printf("%lld",ans);
	return 0;
}
