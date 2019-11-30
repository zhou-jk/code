#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2001;
int n,K;
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
int size[N];
long long dp[N][N];
void dfs(int u,int father)
{
    size[u]=1;
    dp[u][0]=dp[u][1]=0;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs(v,u);
        size[u]+=size[v];
    }
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        for(int j=min(size[u],K);j>=0;j--) 
            for(int k=0;k<=min(j,size[v]);k++) 
                if(dp[u][j-k]!=-1) dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]+(long long)(k*(K-k)+(size[v]-k)*(n-K+k-size[v]))*edge[i].val);
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&K);
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,z);
    } 
    memset(dp,-1,sizeof(dp));
    dfs(1,0);
    printf("%lld",dp[1][K]);
    return 0;
}