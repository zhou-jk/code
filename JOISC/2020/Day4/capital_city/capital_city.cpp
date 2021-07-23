#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n,k;
vector<int>G[N];
int c[N];
vector<int>pos[N];
int root,tot;
int siz[N],Max[N];
bool vis[N];
void getroot(int u,int father)
{
    siz[u]=1,Max[u]=0;
    for(int v:G[u])
    {
        if(v==father) continue;
        if(vis[v]) continue;
        getroot(v,u);
        siz[u]+=siz[v];
        Max[u]=max(Max[u],siz[v]);
    }
    Max[u]=max(Max[u],tot-siz[u]);
    if(Max[u]<Max[root]) root=u;
    return;
}
int dep[N];
int fa[N];
void getdep(int u,int father)
{
    dep[u]=dep[father]+1;
    fa[u]=father;
    for(int v:G[u])
    {
        if(v==father) continue;
        if(vis[v]) continue;
        getdep(v,u);
    }
    return;
}
int cnt[N];
void addcnt(int u,int father,int val)
{
    cnt[c[u]]+=val;
    for(int v:G[u])
    {
        if(v==father) continue;
        if(vis[v]) continue;
        addcnt(v,u,val);
    }
    return;
}
int calc(int rt)
{
    if(cnt[c[rt]]>0) return INF;
    static bool inq[N],inc[N];
    vector<int>pu,pc;
    inc[c[rt]]=true;
    pc.emplace_back(c[rt]);
    queue<int>q;
    for(int u:pos[c[rt]])
        if(u!=rt) inq[u]=true,pu.emplace_back(u),q.emplace(u);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int v=fa[u];
        if(v==rt) continue;
        if(inq[v]) continue;
        if(cnt[c[v]]>0)
        {
            for(int u:pu)
                inq[u]=false;
            for(int c:pc)
                inc[c]=false;
            return INF;
        }
        inq[v]=true,pu.emplace_back(v),q.emplace(v);
        if(!inc[c[v]])
        {
            inc[c[v]]=true;
            pc.emplace_back(c[v]);
            for(int x:pos[c[v]])
                if(!inq[x]&&x!=rt) inq[x]=true,pu.emplace_back(x),q.emplace(x);
        }
    }
    for(int u:pu)
        inq[u]=false;
    for(int c:pc)
        inc[c]=false;
    int res=pc.size()-1;
    return res;
}
int ans=INF;
void solve(int u)
{
    int v=calc(u);
    ans=min(ans,v);
    addcnt(u,0,1);
    vis[u]=true;
    for(int v:G[u])
    {
        if(vis[v]) continue;
        tot=siz[v],root=0;
        getroot(v,0);
        getdep(root,0);
        addcnt(v,0,-1);
        solve(root);
        addcnt(v,0,1);
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
        pos[c[i]].emplace_back(i);
    Max[0]=INF,tot=n;
    getroot(1,0);
    getdep(root,0);
    solve(root);
    printf("%d",ans);
    return 0;
}