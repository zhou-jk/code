#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005*2;
const long long INF=4557430888798830399;
int n,m,L,C,Q;
int a[N],b[N];
int ida[N],idb[N],tot;
bool isb[N];
vector<pair<int,int>>G[N];
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
int rt[N];
long long dis1[N],dis2[N];
long long len[N];
void getdis1(int s)
{
    queue<int>q;
    q.emplace(s);
    dis1[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto [v,w]:GT[u])
            if(dis1[v]>dis1[u]+w)
            {
                dis1[v]=dis1[u]+w;
                q.emplace(v);
            }
    }
    return;
}
void getdis2(int s)
{
    queue<int>q;
    q.emplace(s);
    dis2[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto [v,w]:G[u])
            if(dis2[v]>dis2[u]+w)
            {
                dis2[v]=dis2[u]+w;
                q.emplace(v);
            }
    }
    return;
}
void rebuild()
{
    for(int i=1;i<=tot;i++)
        if(!dfn[i]) tarjan(i);
    map<tuple<int,int,int>,bool>ban;
    for(int i=1;i<=cnt;i++)
        if(bel[G[block[i][0]][0].first]==i)
        {
            for(int u:block[i])
                book[u]=true;
            int now=block[i][0],to=G[now][0].first,val=G[now][0].second;
            ban[{now,to,val}]=true;
            do
            {
                len[i]+=val;
                now=to,to=G[now][0].first,val=G[now][0].second;
            }
            while(now!=block[i][0]);
        }
        else block[i].clear();
    static int deg[N];
    fill(deg+1,deg+tot+1,0);
    for(int u=1;u<=tot;u++)
        for(auto [v,w]:G[u])
            if(!ban[{u,v,w}]) GT[v].emplace_back(u,w),deg[u]++;
    Index=0;
    for(int i=1;i<=tot;i++)
        if(deg[i]==0) dfs(i,0,bel[i]);
    for(int i=1;i<=cnt;i++)
        if(bel[G[block[i][0]][0].first]==i)
        {
            int now=block[i][0],to=G[now][0].first,val=G[now][0].second;
            GT[to].emplace_back(now,val);
        }
    fill(dis1+1,dis1+tot+1,INF);
    fill(dis2+1,dis2+tot+1,INF);
    for(int i=1;i<=tot;i++)
        if(deg[i]==0) rt[bel[i]]=G[i][0].first,getdis1(G[i][0].first),getdis2(G[i][0].first);
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
    int n;
    int C[N];
    BIT()
    {
        memset(C,0,sizeof(C));
        return;
    }
    void init(int _n)
    {
        n=_n;
        return;
    }
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int y)
    {
        for(int i=x;i<=n;i+=lowbit(i))
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
}T1,T2;
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
    for(int i=1;i<=Q;i++)
        q[bel[query[i].v]].emplace_back(query[i]);
    for(int i=1;i<=cnt;i++)
    if(!block[i].empty())
    {
        vector<Query>nquery;
        for(auto [v,t,id]:q[i])
            nquery.emplace_back((Query){v,t,id});
        sort(nquery.begin(),nquery.end(),[=](const Query &a,const Query &b){return a.t+sumt[a.v]<b.t+sumt[b.v];});
        sort(block[i].begin(),block[i].end(),[=](const int &x,const int &y){return sumt[x]<sumt[y];});
        T1.init(tot);
        int j=-1;
        for(auto [v,t,id]:nquery)
            if(!book[v])
            {
                while(j+1<(int)block[i].size()&&sumt[block[i][j+1]]<=t+sumt[v])
                {
                    if(isb[block[i][j+1]]) T1.add(dfn[block[i][j+1]],1);
                    j++;
                }
                ans[id]+=T1.query(dfn[v],dfn[v]+siz[v]-1);
            }
        for(int k=0;k<=j;k++)
            if(isb[block[i][k]]) T1.add(dfn[block[i][k]],-1);
        j=-1;
        for(auto [v,t,id]:nquery)
            if(book[v])
            {
                while(j+1<(int)block[i].size()&&sumt[block[i][j+1]]<=t+sumt[v])
                {
                    if(isb[block[i][j+1]]&&!(dfn[rt[i]]<=dfn[block[i][j+1]]&&dfn[block[i][j+1]]<=dfn[rt[i]]+siz[rt[i]]-1)) T1.add(dfn[block[i][j+1]],1);
                    j++;
                }
                ans[id]+=T1.query(dfn[v],dfn[v]+siz[v]-1);
            }
        for(int k=0;k<=j;k++)
            if(!(dfn[rt[i]]<=dfn[block[i][k]]&&dfn[block[i][k]]<=dfn[rt[i]]+siz[i]-1)) T1.add(dfn[block[i][k]],-1);
        int num=0;
        long long sum=0;
        sort(nquery.begin(),nquery.end(),[=](const Query &a,const Query &b){return a.t<b.t;});
        sort(block[i].begin(),block[i].end(),[=](const int &x,const int &y){return dis1[x]<dis1[y];});
        static long long bv[N];
        static long long tl[N];
        int c=0;
        for(int j=0;j<(int)block[i].size();j++)
            if(isb[block[i][j]]) tl[j]=dis1[block[i][j]]%len[i],bv[++c]=tl[j];
        sort(bv+1,bv+c+1);
        c=unique(bv+1,bv+c+1)-bv-1;
        for(int j=0;j<(int)block[i].size();j++)
            if(isb[block[i][j]]) tl[j]=lower_bound(bv+1,bv+c+1,tl[j])-bv;
        T2.init(c);
        j=-1;
        for(auto [v,t,id]:nquery)
            if(book[v])
            {
                while(j+1<(int)block[i].size()&&dis1[block[i][j+1]]<=t)
                {
                    if(isb[block[i][j+1]]) num++,sum+=dis1[block[i][j+1]]/len[i],T2.add(tl[j+1],1);
                    j++;
                }
                long long x=t+len[i]-dis2[v];
                int xl=upper_bound(bv+1,bv+c+1,x%len[i])-bv;
                ans[id]+=x/len[i]*num-sum-T2.query(xl,c);
            }
        for(int k=0;k<=j;k++)
            if(isb[block[i][k]]) T2.add(tl[k],-1);
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
        while(j+1<=n+n&&a[i]-a[j+1]>=C%L) j++;
        if(a[i]-a[j]>=C%L) G[ida[i]].emplace_back(ida[j],C/L*L+a[i]-a[j]);
    }
    for(int i=m+1,j=1;i<=m+m;i++)
    {
        while(j+1<=n+n&&b[i]>a[j+1]) j++;
        if(b[i]>a[j]) G[idb[i]].emplace_back(ida[j],b[i]-a[j]);
    }
    rebuild();
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
        int v;
        long long t;
        scanf("%d%lld",&v,&t);
        query[i]={ida[v],t,i};
    }
    solve();
    for(int i=1;i<=Q;i++)
        printf("%lld\n",ans[i]);
    return 0;
}