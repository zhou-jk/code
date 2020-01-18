#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=100005,M=300005;
const long long INF=4557430888798830399;
int n,S,E;
struct Edge
{
    int next,val,to;
}edge[M];
int head[N],cnt;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].next=head[u];
    edge[cnt].val=w;
    edge[cnt].to=v;
    head[u]=cnt;
    return;
}
bool book[N];
long long dis[N];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >q;
void dijkstra(int s)
{
    memset(dis,63,sizeof(dis));
    dis[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(book[u]) continue;
        book[u]=true;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].val)
            {
                dis[v]=dis[u]+edge[i].val;
                q.push(make_pair(dis[v],v));
            }
        }
    }
    return;
}
int main()
{
    scanf("%d%d%d",&n,&S,&E);
    for(int i=S;i<E;i++)
        add_edge(i+1,i,0);
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x=max(x,S),y=min(y,E);
        add_edge(x,y+1,z);
    }
    dijkstra(S);
    if(dis[E+1]>=INF) printf("-1");
    else printf("%lld",dis[E+1]);
    return 0;
}