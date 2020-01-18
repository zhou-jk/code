#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=1061109567;
int n,a,b;
struct Edge
{
    int to,val,next;
}edge[10001];
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
    bool operator>(const Node &b)const
    {
        return w>b.w;
    }
};
int dis[101];
bool book[101];
priority_queue<Node,vector<Node>,greater<Node> >q;
int main()
{
    memset(dis,63,sizeof(dis));
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)
    {
        int k,x;
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            scanf("%d",&x);
            if(j==1) add_edge(i,x,0);
            else add_edge(i,x,1);
        }
    }
    dis[a]=0;
    q.push((Node){a,0});
    while(!q.empty())
    {
        int u=q.top().u;
        q.pop();
        if(book[u]) continue;
        book[u]=true;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(!book[v]&&dis[v]>dis[u]+edge[i].val)
            {
                dis[v]=dis[u]+edge[i].val;
                q.push((Node){v,dis[v]});
            }
        }
    }
    if(dis[b]>=INF) printf("-1");
    else printf("%d",dis[b]);
    return 0;
}