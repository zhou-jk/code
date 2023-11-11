#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<map>
#include<vector>
using namespace std;
const int N=200005,M=200005;
int n,m;
struct Edge
{
    int to,next;
}edge[M<<1];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int dfn[N],low[N],Index;
bool book[N];
stack<int>s;
vector<int>block[N];
int bel[N];
int tot;
void tarjan(int u)
{
    dfn[u]=low[u]=++Index;
    book[u]=true;
    s.emplace(u);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(book[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        tot++;
        while(!s.empty()&&s.top()!=u)
        {
            block[tot].emplace_back(s.top());
            bel[s.top()]=tot;
            book[s.top()]=false;
            s.pop();
        }
        block[tot].emplace_back(u);
        bel[u]=tot;
        book[u]=false;
        s.pop();
    }
    return;
}
map<pair<int,int>,bool>e;
vector<int>G[N];
int deg[N];
int in[N],out[N];
bool vis[N];
bool check(int id)
{
    int k=block[id].size();
    if(k==1) return false;
    for(int u:block[id])
        for(int v:G[u])
        {
            out[u]++,in[v]++;
        }
    queue<int>q;
    for(int u:block[id])
        if(in[u]==1&&out[u]==1) q.emplace(u);
    int cnt=0;
    while(!q.empty())
    {
        int u=q.front();
        vis[u]=true;
        q.pop();
        for(int v:G[u])
            if(!vis[v])
            if(e.count(make_pair(v,u)))
            {
                out[v]--,in[v]--,in[u]--,out[u]--;
                if(!vis[v]) cnt++;
                if(in[v]==1&&out[v]==1)
                {
                    q.emplace(v);
                }
            }
    }
    if(cnt==k-1) return false;
    else return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add_edge(x,y);
    }
    for(int i=1;i<=n;i++)
       if(!dfn[i]) tarjan(i);
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(bel[u]==bel[v])
            {
                e[make_pair(u,v)]=true;
                G[u].emplace_back(v);
                continue;
            }
            deg[bel[v]]++;
        }
    for(int i=1;i<=tot;i++)
        if(!deg[i])
        {
            if(!check(i))
            {
                cout<<"NO";
                return 0;
            }
        }
    cout<<"YES";
    return 0;
}