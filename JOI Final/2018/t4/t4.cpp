#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int N=100005,M=200005;
const long long INF=4557430888798830399;
int n,m;
int S,T,U,V;
struct Node
{
    int u,v,w;
}e[M];
struct Graph
{
    struct Edge
    {
        int to,val,next;
    }edge[M<<2];
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
}G[2];
bool book[N*3];
void dijkstra(long long *dis,int id,int s)
{
    for(int i=1;i<=n;i++)
        dis[i]=INF;
    memset(book,false,sizeof(book));
    dis[s]=0;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    q.emplace(0,s);
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(book[u]) continue;
        book[u]=true;
        for(int i=G[id].head[u];i;i=G[id].edge[i].next)
        {
            int v=G[id].edge[i].to;
            if(!book[v]&&dis[v]>dis[u]+G[id].edge[i].val)
            {
                dis[v]=dis[u]+G[id].edge[i].val;
                q.emplace(dis[v],v);
            }
        }
    }
    return;
}
long long dis[3][N];
void Dijkstra(int id,int s)
{
    for(int i=0;i<3;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=INF;
    dis[0][s]=dis[1][s]=dis[2][s]=0;
    memset(book,false,sizeof(book));
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    q.emplace(0,s);
    q.emplace(0,n+s);
    q.emplace(0,2*n+s);
    while(!q.empty())
    {
        pair<long long,int> now=q.top();
        q.pop();
        if(book[now.second]) continue;
        int t=(now.second-1)/n,u=now.second-t*n;
        book[now.second]=true;
        for(int i=G[id].head[u];i;i=G[id].edge[i].next)
        {
            int v=G[id].edge[i].to;
            if(G[id].edge[i].val==0&&t!=1) continue;
            if(t==2)
            {
                if(G[id].edge[i].val!=0)
                {
                    if(dis[2][v]>dis[2][u]+G[id].edge[i].val)
                    {
                        dis[2][v]=dis[2][u]+G[id].edge[i].val;
                        q.emplace(dis[2][v],2*n+v);
                    }
                }
            }
            if(t==1)
            {
                if(G[id].edge[i].val==0&&dis[1][v]>dis[1][u])
                {
                    dis[1][v]=dis[1][u];
                    q.emplace(dis[1][v],n+v);
                }
                else if(dis[2][v]>dis[1][u]+G[id].edge[i].val)
                {
                    dis[2][v]=dis[1][u]+G[id].edge[i].val;
                    q.emplace(dis[2][v],2*n+v);
                }
            }
            if(t==0)
            {
                if(G[id].edge[i].val!=0)
                {
                    if(dis[0][v]>dis[0][u]+G[id].edge[i].val)
                    {
                        dis[0][v]=dis[0][u]+G[id].edge[i].val;
                        q.emplace(dis[0][v],v);
                    }
                    if(dis[1][v]>dis[0][u]+G[id].edge[i].val)
                    {
                        dis[1][v]=dis[0][u]+G[id].edge[i].val;
                        q.emplace(dis[1][v],v+n);
                    }
                }
            }
        }
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d",&S,&T,&U,&V);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        G[0].add_edge(e[i].u,e[i].v,e[i].w);
        G[0].add_edge(e[i].v,e[i].u,e[i].w);
    }
    dijkstra(dis[0],0,S);
    dijkstra(dis[1],0,T);
    for(int i=1;i<=m;i++)
    {
        if(dis[0][e[i].u]+e[i].w+dis[1][e[i].v]==dis[0][T]) G[1].add_edge(e[i].u,e[i].v,0);
        else if(dis[0][e[i].v]+e[i].w+dis[1][e[i].u]==dis[0][T]) G[1].add_edge(e[i].v,e[i].u,0);
        G[1].add_edge(e[i].u,e[i].v,e[i].w),G[1].add_edge(e[i].v,e[i].u,e[i].w);
    }
    Dijkstra(1,U);
    long long ans1=min({dis[0][V],dis[1][V],dis[2][V]});
    Dijkstra(1,V);
    long long ans2=min({dis[0][U],dis[1][U],dis[2][U]});
    printf("%lld",min(ans1,ans2));
    return 0;
}