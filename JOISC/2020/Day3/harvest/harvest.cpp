#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
const long long INF=4557430888798830399;
int n,m,L,C,Q;
int a[N+N],b[N+N];
int ida[N+N],idb[N+N],tot;
bool isb[N+N];
vector<pair<int,int>>G[N+N];
int dfn[N],low[N],Index;
int bel[N],cnt;
vector<int>block[N];
bool book[N];
void tarjan(int u)
{
    static bool vis[N];
    static stack<int>s;
    dfn[u]=low[u]=++Index;
    s.emplace(u);
    vis[u]=true;
    for(auto [v,w]:G[u])
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    if(dfn[u]==low[u])
    {
        cnt++;
        while(s.top()!=u)
        {
            bel[s.top()]=cnt;
            block[cnt].emplace_back(s.top());
            vis[s.top()]=false;
            s.pop();
        }
        bel[u]=cnt;
        block[cnt].emplace_back(u);
        vis[u]=false;
        s.pop();
    }
    return;
}
vector<pair<int,int>>GT[N];
int siz[N];
long long sumt[N];
void dfs(int u,int father,int col)
{
    bel[u]=col;
    dfn[u]=++Index;
    siz[u]=1;
    for(auto [v,w]:GT[u])
    {
        if(v==father) continue;
        sumt[v]=sumt[u]+w; 
        dfs(v,u,col);
        siz[u]+=siz[v];
    }
    return;
}
long long dis[N];
long long len[N];
void getdis(int s)
{
    queue<int>q;
    q.emplace(s);
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto [v,w]:GT[u])
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q.emplace(v);
            }
    }
    return;
}
void rebuild()
{
    for(int i=1;i<=tot;i++)
        if(!dfn[i]) tarjan(i);
    for(int i=1;i<=cnt;i++)
        if((int)block[i].size()>1)
            for(int u:block[i])
                book[u]=true;
    map<tuple<int,int,int>,bool>ban;
    for(int i=1;i<=cnt;i++)
        if((int)block[i].size()>1)
        {
            int now=block[i][0],to=G[now][0].first,val=G[now][0].second;
            ban[{now,to,val}]=true;
            // cerr<<"ban"<<now<<" "<<to<<" "<<val<<"\n";
        }
    static int deg[N];
    fill(deg+1,deg+tot+1,0);
    for(int u=1;u<=tot;u++)
        for(auto [v,w]:G[u])
            if(!ban[{u,v,w}]) GT[v].emplace_back(u,w),deg[u]++;
    for(int i=1;i<=tot;i++)
        if(deg[i]==0) dfs(i,0,bel[i]);
    for(int i=1;i<=cnt;i++)
        if((int)block[i].size()>1)
        {
            int now=block[i][0],to=G[now][0].first,val=G[now][0].second;
            GT[to].emplace_back(now,val);
        }
    fill(dis+1,dis+tot+1,INF);
    for(int i=1;i<=cnt;i++)
        if(deg[i]==0) getdis(G[i][0].first);
    for(int i=1;i<=cnt;i++)
        if((int)block[i].size()>1)
        {
            int now=block[i][0],to=G[now][0].first,val=G[now][0].second;
            do
            {
                len[i]+=val;
                now=to,to=G[now][0].first,val=G[now][0].second;
            }
            while(now!=block[i][0]);
        }
    for(int i=1;i<=tot;i++)
        block[bel[i]].emplace_back(i);
    for(int i=1;i<=cnt;i++)
    {
        sort(block[i].begin(),block[i].end());
        block[i].erase(unique(block[i].begin(),block[i].end()),block[i].end());
    }
    return;
}
struct BIT
{
    int C[N];
    BIT()
    {
        memset(C,0,sizeof(C));
        return;
    }
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int y)
    {
        for(int i=x;i<=tot;i+=lowbit(i))
            C[i]+=y;
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=C[i];
        return res;
    }
    int query(int l,int r)
    {
        return getsum(r)-getsum(l-1);
    }
}T;
struct Query
{
    int v;
    long long t;
    int id;
}query[N];
long long ans[N];
vector<Query>q[N];
void solve()
{
    for(int i=1;i<=cnt;i++)
        sort(block[i].begin(),block[i].end(),[=](const int &x,const int &y){return sumt[x]<sumt[y];});
    for(int i=1;i<=Q;i++)
        q[bel[query[i].v]].emplace_back(query[i]);
    for(int i=1;i<=cnt;i++)
    {
        vector<Query>ncir;
        for(auto [v,t,id]:q[i])
            if(!book[v]) ncir.emplace_back((Query){v,t,id});
        sort(ncir.begin(),ncir.end(),[=](const Query &a,const Query &b){return a.t<b.t;});
        int j=-1;
        for(auto [v,t,id]:ncir)
        {
            while(j+1<(int)block[i].size()&&sumt[block[i][j+1]]<=t) T.add(dfn[block[i][j+1]],1),j++;
            ans[id]=T.query(dfn[v],dfn[v]+siz[v]-1);
        }
    }
    return;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&L,&C);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        ida[i]=ida[i+n]=++tot,a[i+n]=a[i]+L;
    for(int i=1;i<=m;i++)
        idb[i]=idb[i+m]=++tot,b[i+m]=b[i]+L,isb[idb[i]]=true;
    for(int i=n+1,j=1;i<=n+n;i++)
    {
        while(j+1<=n+n&&a[i]-a[j+1]>=C) j++;
        if(a[i]-a[j]>=C) G[ida[i]].emplace_back(ida[j],a[i]-a[j]);
    }
    for(int i=m+1,j=1;i<=m+m;i++)
    {
        while(j+1<=n+n&&b[i]>a[j+1]) j++;
        if(b[i]>a[j]) G[idb[i]].emplace_back(ida[j],b[i]-a[j]);
    }
    rebuild();
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
        scanf("%d%lld",&query[i].v,&query[i].t),query[i].id=i;
    solve();
    for(int i=1;i<=Q;i++)
        printf("%lld\n",ans[i]);
    return 0;
}