#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=55;
const long long INF=4557430888798830399;
struct Edge
{
    int to,next;
    int cost;
    long long flow;
}edge[N*N*20];
int cur[N*N*3],head[N*N*3],cnt=1;
int s,t;
void add_edge(int u,int v,int c,int f)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].cost=c;
    edge[cnt].flow=f;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
void add(int u,int v,int c,int f)
{
    add_edge(u,v,c,f);
    add_edge(v,u,-c,0);
    return;
}
long long dis[N*N*3];
bool spfa()
{
    static bool vis[N*N*3];
    memset(vis,false,sizeof(vis));
    memset(dis,63,sizeof(dis));
    queue<int>q;
    vis[s]=true;
    dis[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].flow<=0) continue;
            if(dis[v]>dis[u]+edge[i].cost)
            {
                dis[v]=dis[u]+edge[i].cost;
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    return dis[t]!=INF;
}
bool book[N*N*3];
pair<long long,long long> dfs(int u,long long flow)
{
    if(u==t||flow==0) return make_pair(flow,0);
    book[u]=true;
    long long used=0,res=0;
    for(int &i=cur[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(book[v]||dis[v]!=dis[u]+edge[i].cost||edge[i].flow<=0) continue;
        pair<long long,long long>t=dfs(v,min(flow,edge[i].flow));
        long long now=t.first;
        res+=t.second+now*edge[i].cost;
        flow-=now;
        edge[i].flow-=now;
        edge[i^1].flow+=now;
        used+=now;
        if(flow==0) break;
    }
    book[u]=false;
    return make_pair(used,res);
}
pair<long long,long long> dinic()
{
    long long ans=0,Min=0;
    while(spfa())
    {
        memcpy(cur,head,sizeof(head));
        pair<long long,long long> res=dfs(s,INF);
        ans+=res.first,Min+=res.second;
    }
    return make_pair(ans,Min);
}
int n,m;
int w[N][N],p[N][N];
int tot;
int id[N][N],l[N][N],u[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>p[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>w[i][j];
    tot=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            id[i][j]=++tot;
            if(i-1>=1) l[i][j]=++tot;
            if(j-1>=1) u[i][j]=++tot;
        }
    s=++tot,t=++tot;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            add(s,id[i][j],0,w[i][j]);
            if(i==1||i==n) add(id[i][j],t,0,1);
            if(j==1||j==m) add(id[i][j],t,0,1);
            if(i-1>=1)
            {
                add(id[i][j],l[i][j],0,1);
                add(id[i-1][j],l[i][j],0,1);
                add(l[i][j],t,0,1);
                add(l[i][j],t,p[i][j]*p[i-1][j],1);
            }
            if(j-1>=1)
            {
                add(id[i][j],u[i][j],0,1);
                add(id[i][j-1],u[i][j],0,1);
                add(u[i][j],t,0,1);
                add(u[i][j],t,p[i][j]*p[i][j-1],1);
            }
        }
    long long ans=dinic().second;
    cout<<ans;
    return 0;
}