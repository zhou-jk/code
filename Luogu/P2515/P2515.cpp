#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int N=101,M=501;
int n,m;
int w[N],c[N];
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
int dfn[N],low[N],Index;
bool book[N];
int belong[N],tot;
int sumw[N],sumc[N];
stack<int>s;
void tarjan(int u)
{
    dfn[u]=low[u]=++Index;
    s.push(u);
    book[u]=true;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(book[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        tot++;
        while(s.top()!=u)
        {
            belong[s.top()]=tot;
            sumw[tot]+=w[s.top()];
            sumc[tot]+=c[s.top()];
            book[s.top()]=false;
            s.pop();
        }
        belong[u]=tot;
        sumw[tot]+=w[u];
        sumc[tot]+=c[u];
        book[u]=false;
        s.pop();
    }
    return;
}
int dp[N][M];
void dfs(int u)
{
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        dfs(v);
        for(int j=m;j>=0;j--)
            for(int k=j;k>=0;k--)
                dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
    }
    for(int i=m;i>=0;i--)
        if(i>=sumw[u]) dp[u][i]=dp[u][i-sumw[u]]+sumc[u];
        else dp[u][i]=0;
    return;
}
int d[N];
int in[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
        if(d[i]!=0) add_edge(d[i],i);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i);
    cnt=0;
    memset(head,0,sizeof(head));
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0||belong[i]==belong[d[i]])continue;
        add_edge(belong[d[i]],belong[i]);
        in[belong[i]]++;
    }
    for(int i=1;i<=tot;i++)
        if(in[i]==0) add_edge(0,i);
    dfs(0);
    int ans=0;
    for(int i=0;i<=m;i++)
        ans=max(ans,dp[0][i]);
    printf("%d",ans);
    return 0;
}