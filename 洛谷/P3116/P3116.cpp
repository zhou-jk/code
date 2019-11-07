#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int M=10000;
int n,m;
struct Edge
{
	int to,val,w,next;
}edge[M+1];
int head[1001],cnt;
int in[1001];
bool dp[1001][M+1],f[1001][M+1];
queue<int>q;
void add_edge(int u,int v,int val,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=val;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
void topsort()
{
    for(int i=1;i<=n;i++)
        if(in[i]==0) q.push(i);
	while(!q.empty())
    {
		int u=q.front();
        q.pop();
		for(int i=head[u];i;i=edge[i].next)
        {
			int v=edge[i].to;
            for(int j=edge[i].val;j<=M;j++)
                dp[v][j]|=dp[u][j-edge[i].val];
            for(int j=edge[i].w;j<=M;j++)
                f[v][j]|=f[u][j-edge[i].w];
			in[v]--;
            if(in[v]==0) q.push(v);
		}
	}
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y,z1,z2;
        scanf("%d%d%d%d",&x,&y,&z1,&z2);
		add_edge(x,y,z1,z2);
		in[y]++;
	}
	dp[1][0]=f[1][0]=1;
	topsort();
	for(int i=0;i<=M;i++)
		if(dp[n][i]&&f[n][i])
        {
			printf("%d",i);
            return 0;
		}
	printf("IMPOSSIBLE");
	return 0;
}