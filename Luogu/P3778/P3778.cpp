#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const double eps=1e-6;
const int N=101,P=1001;
const int INF=1061109567;
int n,m,K;
int b[P][P],s[P][P];
int f[N][N],w[N][N];
struct Edge
{
    int to,next;
    double val;
}edge[N*N];
int head[N],cnt;
void add_edge(int u,int v,double w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
double dis[N];
queue<int>q;
bool vis[N];
int num[N];
bool check(double x)
{
    memset(head,0,sizeof(head));
    cnt=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(f[i][j]<INF&&i!=j) add_edge(i,j,f[i][j]*x-w[i][j]);
    memset(dis,0,sizeof(dis));
    memset(vis,true,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        q.push(i);
        num[i]=1;
    }
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
                    num[v]++;
                    if(num[v]>n) return true;
                    q.push(v);
                }
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d%d%d",&n,&m,&K);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=K;j++)
            scanf("%d%d",&b[i][j],&s[i][j]);
    K++;
    memset(f,63,sizeof(f));
    for(int i=1;i<=n;i++)
        f[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        f[u][v]=w;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(f[i][j]>f[i][k]+f[k][j]) f[i][j]=f[i][k]+f[k][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=K;k++)
                if(s[j][k]!=-1&&b[i][k]!=-1) w[i][j]=max(w[i][j],s[j][k]-b[i][k]);
    if(!check(1))
    {
        printf("0");
        return 0;
    }
    double l=0,r=1e9;
    while(r-l>eps)
    {
        double mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    printf("%d",(int)r);
    return 0;
}