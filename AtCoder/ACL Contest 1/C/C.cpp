#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=55,M=100005;
const int INF=1061109567;
const long long LINF=4557430888798830399;
struct Edge
{
    int to,next;
    long long cost,flow;
}edge[M<<1];
int cur[N*N],head[N*N],cnt=1;
int S,T;
void add_edge(int u,int v,int f,int c)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].flow=f;
    edge[cnt].cost=c;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
void add(int u,int v,int f,int c)
{
    add_edge(u,v,f,c);
    add_edge(v,u,0,-c);
    return;
}
long long dis[N*N];
bool spfa()
{
    static bool vis[N*N];
    memset(vis,false,sizeof(vis));
    for(int i=0;i<N*N;i++)
        dis[i]=-LINF;
    queue<int>q;
    dis[S]=0;
    vis[S]=true;
    q.push(S);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].flow<=0) continue;
            if(dis[v]<dis[u]+edge[i].cost)
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
    return dis[T]!=-LINF;
}
bool book[N*N];
pair<long long,long long> dfs(int u,long long flow)
{
    if(u==T||flow==0) return make_pair(flow,0LL);
    book[u]=true;
    long long used=0,res=0;
    for(int &i=cur[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(book[v]||dis[v]!=dis[u]+edge[i].cost||edge[i].flow<=0) continue;
        pair<long long,long long>T=dfs(v,min(flow,edge[i].flow));
        long long now=T.first;
        res+=T.second+now*edge[i].cost;
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
    int flow=0,cost=0;
    while(spfa())
    {
        memcpy(cur,head,sizeof(head));
        pair<long long,long long> res=dfs(S,INF);
        flow+=res.first,cost+=res.second;
    }
    return {flow,cost};
}
int n,m;
char s[N][N];
int id[N][N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)  
        scanf("%s",s[i]+1);
    int tot=-1;
    S=++tot;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            id[i][j]=++tot;
    T=++tot;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]!='#')
            {
                if(i+1<=n&&s[i+1][j]!='#') add(id[i][j],id[i+1][j],INF,1);
                if(j+1<=m&&s[i][j+1]!='#') add(id[i][j],id[i][j+1],INF,1);
                if(s[i][j]=='o') add(S,id[i][j],1,0);
                add(id[i][j],T,1,0);   
            }
    pair<long long,long long> ans=dinic();
    printf("%lld",ans.second);
    return 0;
}