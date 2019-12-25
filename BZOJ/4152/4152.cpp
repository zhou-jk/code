#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int N=200001;
int n;
struct Node
{
    int x,y,id;
}p[N];
bool cmpx(Node a,Node b)
{
    return a.x<b.x;
}
bool cmpy(Node a,Node b)
{
    return a.y<b.y;
}
struct Edge
{
    int to,val,next;
}edge[N<<2];
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
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
long long dis[N];
bool book[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&p[i].x,&p[i].y),p[i].id=i;
    sort(p+1,p+n+1,cmpx);
    for(int i=1;i<n;i++)
        add_edge(p[i].id,p[i+1].id,p[i+1].x-p[i].x),add_edge(p[i+1].id,p[i].id,p[i+1].x-p[i].x);
    sort(p+1,p+n+1,cmpy);
    for(int i=1;i<n;i++)
        add_edge(p[i].id,p[i+1].id,p[i+1].y-p[i].y),add_edge(p[i+1].id,p[i].id,p[i+1].y-p[i].y);
    memset(dis,63,sizeof(dis));
    dis[1]=0;
    q.push(make_pair(0,1));
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(book[u]) continue;
        book[u]=true;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(!book[v]&&dis[v]>dis[u]+edge[i].val)
            {
                dis[v]=dis[u]+edge[i].val;
                q.push(make_pair(dis[v],v));
            }
        }
    }
    printf("%lld",dis[n]);
    return 0;
}