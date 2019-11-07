#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=1061109567;
int n,m,k,e,d;
int p[101],a[101],b[101],c[101][101],dp[101];
bool book[101];
struct Edge
{
    int to,val,next;
}edge[20001];
int head[101],cnt;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
struct Node
{
    int u,w;
    bool operator > (const Node &b)const
    {
        return w>b.w;
    }
};
priority_queue<Node,vector<Node>,greater<Node> >q;
int dis[101];
int dijkstra(int l,int r)
{
    memset(dis,63,sizeof(dis));
    memset(book,false,sizeof(book));
    for(int i=1;i<=d;i++)
        if(l<=b[i]&&r>=a[i]) book[p[i]]=true;
    dis[1]=0;
    q.push((Node){1,0});
    while(!q.empty())
    {
        int u=q.top().u;
        q.pop();
        if(book[u]) continue;
        book[u]=true;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].val)
            {
                dis[v]=dis[u]+edge[i].val;
                q.push((Node){v,dis[v]});
            }
        }
    }
    return dis[m];
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&e);
    for(int i=1;i<=e;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    scanf("%d",&d);
    for(int i=1;i<=d;i++)
        scanf("%d%d%d",&p[i],&a[i],&b[i]);
    for(int i=0;i<=n;i++)
        for(int j=i;j<=n;j++)
            c[i][j]=dijkstra(i,j);
    memset(dp,63,sizeof(dp));
    dp[0]=-k;
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
            if(c[j+1][i]!=INF&&dp[j]!=INF) dp[i]=min(dp[i],dp[j]+(i-j)*c[j+1][i]+k);
    printf("%d",dp[n]);
    return 0;
}