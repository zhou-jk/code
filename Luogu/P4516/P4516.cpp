#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100001;
const int MOD=1000000007;
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
}
int n,K;
int size[N];
int dp[N][101][2][2];
int f[101][2][2];
void dfs(int u,int father)
{
    size[u]=1;
    dp[u][0][0][0]=dp[u][1][1][0]=1;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs(v,u);
        for(int j=0;j<=size[u]&&j<=K;j++)
            for(int k=0;k<=size[v]&&j+k<=K;k++)
            {
                f[j+k][0][0]=(f[j+k][0][0]+(long long)dp[u][j][0][0]*dp[v][k][0][1]%MOD)%MOD;
                f[j+k][0][1]=(f[j+k][0][1]+(long long)dp[u][j][0][0]*dp[v][k][1][1]%MOD)%MOD;
                f[j+k][0][1]=(f[j+k][0][1]+dp[u][j][0][1]*((long long)dp[v][k][0][1]+dp[v][k][1][1])%MOD)%MOD;
                f[j+k][1][0]=(f[j+k][1][0]+dp[u][j][1][0]*((long long)dp[v][k][0][0]+dp[v][k][0][1])%MOD)%MOD;
                f[j+k][1][1]=(f[j+k][1][1]+dp[u][j][1][0]*((long long)dp[v][k][1][0]+dp[v][k][1][1])%MOD)%MOD;
                f[j+k][1][1]=(f[j+k][1][1]+dp[u][j][1][1]*((((long long)dp[v][k][0][0]+dp[v][k][0][1])%MOD+((long long)dp[v][k][1][0]+dp[v][k][1][1])%MOD)%MOD)%MOD);
            }
        size[u]+=size[v];
        for(int j=0;j<=size[u]&&j<=K;j++)
        {
            dp[u][j][0][0]=f[j][0][0];
            dp[u][j][0][1]=f[j][0][1];
            dp[u][j][1][0]=f[j][1][0];
            dp[u][j][1][1]=f[j][1][1];
        }
        memset(f,0,sizeof(f));
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&K);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs(1,0);
    printf("%lld",((long long)dp[1][K][0][1]+dp[1][K][1][1])%MOD);
    return 0;
}