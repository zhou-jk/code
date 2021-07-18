#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int N=100005;
int n,m;
int fa[N],siz[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    else return fa[v]=getf(fa[v]);
}
set<pair<int,int>>to[N],from[N];
long long ans;
void del(set<pair<int,int>> &S,int x)
{
    while(true)
    {
        set<pair<int,int>>::iterator it=S.lower_bound({x,0});
        if(it==S.end()||it->first!=x) break;
        S.erase(it);
    }
    return;
}
bool find(set<pair<int,int>> &S,int x)
{
    set<pair<int,int>>::iterator it=S.lower_bound({x,0});
    return it!=S.end()&&it->first==x;
}
void merge(int u,int v)
{
    if(getf(u)==getf(v)) return;
    if(from[u].size()+to[u].size()<from[v].size()+to[v].size()) swap(u,v);
    ans-=1LL*siz[u]*(siz[u]-1);
    ans-=1LL*siz[v]*(siz[v]-1);
    ans-=1LL*from[u].size()*siz[u]; 
    ans-=1LL*from[v].size()*siz[v];
    siz[u]+=siz[v],siz[v]=0;
    fa[v]=u;
    del(from[u],v);
    del(from[v],u);
    set<int>pos;
    for(auto it:from[v])
    {
        int x=it.first,y=it.second;
        to[x].erase(to[x].find({v,y}));
        to[x].insert({u,y});
        from[u].insert(it);
        if(find(to[u],x)) pos.insert(x);
    }
    ans+=1LL*from[u].size()*siz[u];
    from[v].clear();
    del(to[u],v);
    del(to[v],u);
    for(auto it:to[v])
    {
        int x=it.first,y=it.second;
        from[x].erase(from[x].find({v,y}));
        from[x].insert({u,y});
        to[u].insert(it);
        if(find(from[u],x)) pos.insert(x);
    }
    to[v].clear();
    ans+=1LL*siz[u]*(siz[u]-1);
    for(int x:pos)
        merge(x,u);
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        fa[i]=i,siz[i]=1;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int u=getf(a),v=getf(b);
        if(u!=v)
        {
            if(to[u].find({v,a})==to[u].end()) ans+=siz[v];
            to[u].insert({v,a}),from[v].insert({u,a});
            if(from[u].lower_bound({v,0})!=from[u].end()&&from[u].lower_bound({v,0})->first==v) merge(u,v);
        }
        printf("%lld\n",ans);
    }
    return 0;
}