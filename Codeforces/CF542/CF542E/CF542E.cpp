#include<iostream>
#include<cstdio>  
#include<cstring>
#include<queue>
using namespace std;
const int N=200001;
int n,m;
int ans;
struct Edge
{
    int to,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int record[N],num;
bool book[N];
int col[N];
void dfs(int u,int color)
{
    book[u]=true;
    col[u]=color;
    record[++num]=u;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(book[v])
        {
            if(col[u]==col[v])
            {
                printf("-1");
                exit(0);
            }
        }
        else dfs(v,color^1);
    }
    return;
}
queue<int>q;
int dis[N];
bool vis[N];
int bfs(int s)
{
    memset(dis,0,sizeof(dis));
    memset(vis,false,sizeof(vis));
    dis[s]=0;
    vis[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(vis[v]) continue;
            vis[v]=true;
            dis[v]=dis[u]+1;
            q.push(v);
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)
        res=max(res,dis[i]);
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=n;i++)
        if(!book[i])
        {
            num=0;
            dfs(i,0);
            int res=0;
            for(int j=1;j<=num;j++)
                res=max(res,bfs(record[j]));
            ans+=res;
        }
    printf("%d",ans);
    return 0;
}