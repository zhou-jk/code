#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=100001;
int n,m,Q;
struct Edge
{
    int to,next;
}edge[N<<1];
int head[N],cnt;
int in[N];
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
struct Node
{
    int u,w;
    bool k;
    bool operator>(const Node &b)const
    {
        return w>b.w;
    }
};
priority_queue<Node,vector<Node>,greater<Node> >q;
int dis[N][2];
bool book[N][2];
void dijkstra(int s)
{
    memset(dis,63,sizeof(dis));
    dis[s][0]=0;
    q.push((Node){s,0,false});
    while(!q.empty())
    {
        int u=q.top().u,k=q.top().k;
        q.pop();
        if(book[u][k]) continue;
        book[u][k]=true;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(!book[v][k^1]&&dis[v][k^1]>dis[u][k]+1)
            {
                dis[v][k^1]=dis[u][k]+1;
                q.push((Node){v,dis[v][k^1],k^1});
            }
        }
    }
    return;
}
int main()
{
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
        in[x]++,in[y]++;
    }
    dijkstra(1);
    while(Q--)
    {
        int a,l;
        scanf("%d%d",&a,&l);
        if(in[a]==0) printf("No\n");
        else if(dis[a][l%2]>l) printf("No\n");
        else if((dis[a][l%2]-l)%2==0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}