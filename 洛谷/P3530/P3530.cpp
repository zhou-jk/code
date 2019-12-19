#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=601;
const int INF=1061109567;
int n,m1,m2;
int dis[N][N];
int dfn[N],low[N],Index;
int col[N],tot;
bool vis[N],book[N][N];
stack<int>s;
void tarjan(int u)
{
    dfn[u]=low[u]=++Index;
    s.push(u);
    vis[u]=true;
    for(int v=1;v<=n;v++)
        if(v!=u&&book[u][v])
        {
            if(!dfn[v])
            {
                tarjan(v);
                low[u]=min(low[u],low[v]);
            } 
            else if(vis[v]) low[u]=min(low[u],dfn[v]);
        }
    if(dfn[u]==low[u])
    {
        tot++;
        while(s.top()!=u)
        {
            col[s.top()]=tot;
            vis[s.top()]=false;
            s.pop();
        }
        col[u]=tot;
        vis[u]=false;
        s.pop();
    }
    return;
}
int ans[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=i==j?0:INF;
    scanf("%d%d",&m1,&m2);
    while(m1--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        dis[x][y]=min(dis[x][y],1);
        dis[y][x]=min(dis[y][x],-1);
        book[x][y]=book[y][x]=true;
    }
    while(m2--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        dis[y][x]=min(dis[y][x],0);
        book[y][x]=true;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=n;i++)
        if(dis[i][i]<0)
        {
            printf("NIE");
            return 0;
        }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i);
    fill(ans+1,ans+tot+1,1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j&&col[i]==col[j]) ans[col[i]]=max(ans[col[i]],dis[i][j]+1);
    printf("%d",accumulate(ans+1,ans+tot+1,0));
    return 0;
}