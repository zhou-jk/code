#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=10001,M=200001,K=21;
const int INF=1061109567;
struct Node
{
    int u,val,tot;
    bool operator>(const Node &b)const
    {
        return val>b.val;
    }
};
priority_queue<Node,vector<Node>,greater<Node> >q;
int T,n,m,k,s,t;
int a[N];
struct Edge
{
    int to,val,next;
}edge[M];
int head[N],cnt;
void add_edge(int u,int a,int w)
{
    cnt++;
    edge[cnt].to=a;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int f[N][K];
bool vis[N][K];
int dijkstra(int S,int T)
{
    memset(f,63,sizeof(f));
    f[S][k+a[S]]=0;
    q.push((Node){S,f[S][k+a[S]],k+a[S]});
    while(!q.empty())
    {
        int u=q.top().u,tot=q.top().tot;
        q.pop();
        if(vis[u][tot]) continue;
        vis[u][tot]=true;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(tot+a[v]<0||tot+a[v]>2*k) continue;
            if(f[v][tot+a[v]]>f[u][tot]+edge[i].val)
            {
                f[v][tot+a[v]]=f[u][tot]+edge[i].val;
                q.push((Node){v,f[v][tot+a[v]],tot+a[v]});
            }
        }
    }
    int ans=INF;
    for(int i=0;i<=2*k;i++)
        ans=min(ans,f[T][i]);
    if(ans>=INF) return -1;
    else return ans;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,false,sizeof(vis));
        memset(head,0,sizeof(head));
        cnt=0;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==2) a[i]=-1;
        }
        for(int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add_edge(x,y,z);
            add_edge(y,x,z);
        }
        scanf("%d%d",&s,&t);
        printf("%d\n",dijkstra(s,t));
    }
    return 0;
}