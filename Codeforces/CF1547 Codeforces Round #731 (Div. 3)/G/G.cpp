#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
const int N=400005;
int n,m;
bool book[N];
vector<int>G[N],GN[N];
int dfn[N],low[N],Index;
int bel[N],tot;
bool vis[N];
vector<int>block[N];
stack<int>s;
void tarjan(int u)
{
    dfn[u]=low[u]=++Index;
    vis[u]=true;
    s.emplace(u);
    for(int v:G[u])
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    if(dfn[u]==low[u])
    {
        tot++;
        block[tot].clear();
        while(s.top()!=u)
        {
            bel[s.top()]=tot;
            block[tot].emplace_back(s.top());
            vis[s.top()]=false;
            s.pop();
        }
        bel[u]=tot;
        block[tot].emplace_back(u);
        vis[u]=false;
        s.pop();
    }
    return;
}
void solve()
{
    scanf("%d%d",&n,&m);
    fill(book+1,book+n+1,false);
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==y) book[x]=true;
        else G[x].emplace_back(y);
    }
    fill(dfn+1,dfn+n+1,0);
    fill(low+1,low+n+1,0);
    Index=0;
    fill(vis+1,vis+n+1,false);
    tot=0;
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i);
    for(int i=1;i<=tot;i++)
        GN[i].clear();
    static int deg[N];
    fill(deg+1,deg+tot+1,0);
    for(int u=1;u<=n;u++)
        for(int v:G[u])
            if(bel[u]!=bel[v]) GN[bel[u]].emplace_back(bel[v]),deg[bel[v]]++;
    static int ansb[N];
    fill(ansb+1,ansb+tot+1,0);
    if((int)block[bel[1]].size()>1||((int)block[bel[1]].size()==1&&book[1])) ansb[bel[1]]=-1;
    else ansb[bel[1]]=1;
    queue<int>q;
    for(int i=1;i<=tot;i++)
        if(deg[i]==0) q.emplace(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:GN[u])
        {
            deg[v]--;
            if(ansb[u]==-1) ansb[v]=-1;
            else if(ansb[u]==1||ansb[u]==2)
            {
                if(ansb[v]!=-1) ansb[v]=min(ansb[v]+ansb[u],2);
            }
            if(ansb[u]!=0)
            {
                if((int)block[v].size()>1||((int)block[v].size()==1&&book[block[v][0]])) ansb[v]=-1;
            }
            if(deg[v]==0) q.emplace(v);
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ansb[bel[i]]);
    printf("\n");
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}