#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Edge
{
    int to,val,next;
}edge[12001];
int head[12001],cnt;
int dp[3001][3001],a[3001];
int n,m,size[3001],num[3001];
void add_edge(int u,int v,int w)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].val=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
    return;
}
void dfs(int u,int fa)
{
	dp[u][0]=0;
	for(int i=head[u];i;i=edge[i].next)
    {
		int v=edge[i].to;
		if(v==fa) continue;
		dfs(v,u); 
		size[u]+=size[v];
		for(int j=size[u];j;j--)
			for(int k=1;k<=min(j,size[v]);k++)
				dp[u][j]=max(dp[u][j],dp[v][k]+dp[u][j-k]-edge[i].val);
	}
	if(num[u]==1) dp[u][1]=a[u],size[u]=1;
    return;
}
int main()
{
	memset(dp,-63,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-m;i++)
    {
        int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
        {
            int x,z;
			scanf("%d%d",&x,&z);
			num[x]++,num[i]++;
			add_edge(i,x,z);
            add_edge(x,i,z);
		}
	}
	for(int i=n-m+1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,0);
	for(int i=m;i>=0;i--)
		if(dp[1][i]>=0)
        {
			printf("%d",i);
			return 0;
        }
	return 0;
}