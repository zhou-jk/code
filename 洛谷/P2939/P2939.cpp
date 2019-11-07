#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n,m,k;
struct Edge
{
    int to,val,next;
}edge[100005];
int head[10005],cnt;
struct Node
{
    int u,w,sum;
    bool operator>(const Node &b)const
    {
        return w>b.w;
    }
};
priority_queue<Node,vector<Node>,greater<Node> >q;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int dis[10005][25];
bool vis[10005][25];
void dijsktra(int r)
{
    memset(dis,63,sizeof(dis));
    dis[r][0]=0;
    q.push((Node){r,0,0});
    while(!q.empty())
    {
        int u=q.top().u,sum=q.top().sum;
        q.pop();
        if(vis[u][sum]) continue;
        vis[u][sum]=true;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v][sum]>dis[u][sum]+edge[i].val)
            {
                dis[v][sum]=dis[u][sum]+edge[i].val;
                q.push((Node){v,dis[v][sum],sum});
            }
            if(dis[v][sum+1]>dis[u][sum]&&sum+1<=k)
            {
                dis[v][sum+1]=dis[u][sum];
                q.push((Node){v,dis[v][sum+1],sum+1});
            }
        }
    }
    return;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    dijsktra(1);
    printf("%d",dis[n][k]);
    return 0;
}