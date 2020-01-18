#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=100010,M=400010,K=55;
const int INF=1061109567;
int T,n,m,k,p;
int dis[N];
int f[N][K];
bool d[N][K],vis[N],res;
struct Edge
{
    int to,val,next;
}edge[M],e[M];
int head[N],cnt;
int Head[N],Cnt;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
void Add_edge(int u,int v,int w)
{
    Cnt++;
    e[Cnt].to=v;
    e[Cnt].val=w;
    e[Cnt].next=Head[u];
    Head[u]=Cnt;
    return;
}
void spfa()
{
    queue<int>q;
    q.push(1);
    vis[1]=true;
    dis[1]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].val)
            {
                dis[v]=dis[u]+edge[i].val;
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    return;
}
int dfs(int u,int dep)
{
    if(d[u][dep])
    {
        res=false;
        return 0;
    } 
    if(f[u][dep]!=-1) return f[u][dep];
    d[u][dep]=true;
    f[u][dep]=0;
    for(int i=Head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        if(dis[u]+dep-dis[v]-e[i].val>=0) f[u][dep]=(f[u][dep]+dfs(v,dis[u]+dep-dis[v]-e[i].val))%p;
    }
    d[u][dep]=false;
    return f[u][dep];
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&k,&p);
        cnt=Cnt=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k+1;j++)
                d[i][j]=0,f[i][j]=-1;
            dis[i]=INF;
            head[i]=Head[i]=0;
            vis[i]=false;
        }
        for(int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add_edge(x,y,z);
            Add_edge(y,x,z);
        }
        spfa();
        f[1][0]=1;
        res=true;
        int ans=0;
        for(int i=0;i<=k;i++) 
            ans=(ans+dfs(n,i))%p;
        dfs(n,k+1);
        if(res) printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}