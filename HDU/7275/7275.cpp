#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=3005;
const int INF=1061109567;
int n,m;
vector<int>G[N];
int dep[N],fa[N];
int dfn[N],Index,siz[N];
void dfs(int u,int father)
{
    fa[u]=father;
    dep[u]=dep[father]+1;
    dfn[u]=++Index;
    siz[u]=1;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
    return;
}
int LCA(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    while(u!=v)
    {
        u=fa[u];
        if(dep[u]<dep[v]) swap(u,v);
    }
    return u;
}
vector<int> path(int u,int v)
{
    vector<int>p;
    while(u!=v)
    {
        p.emplace_back(u);
        u=fa[u];
    }
    p.emplace_back(v);
    return p;
}
bool in(int u,int x)
{
    return dfn[u]<=dfn[x]&&dfn[x]<=dfn[u]+siz[u]-1;
}
int dis(int u,int lca,int x)
{
    if(in(x,u)) return dep[u]-dep[x];
    else return dep[u]-dep[lca]+dep[x]-dep[lca];
}
int ex_gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int d=ex_gcd(b,a%b,x,y);
    int tmp=x;
    x=y,y=tmp-a/b*y;
    return d;
}
bool calc(int a,int b,int c,int &x,int &y)
{
    int d=ex_gcd(a,b,x,y);
    if(c%d!=0) return false;
    x=x*c/d,y=y*c/d;
    int dx=b/d,dy=-a/d;
    if(dx<0) dx=-dx,dy=-dy;
    if(x<0)
    {
        int t=(0-x+dx-1)/dx;
        x+=t*dx,y+=t*dy;
    }
    if(x>0&&y>0)
    {
        if(dy>0)
        {
            int t=min(x/dx,y/dy);
            x-=t*dx,y-=t*dy;
        }
        else
        {
            int t=x/dx;
            x-=t*dx,y-=t*dy;
        }
    }
    if(y<0) return false;
    return true;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    Index=0;
    dfs(1,0);
    while(m--)
    {
        int sa,ta,sb,tb;
        cin>>sa>>ta>>sb>>tb;
        int lcaa=LCA(sa,ta),lcab=LCA(sb,tb);
        vector<int>a1=path(sa,lcaa),a2=path(ta,lcaa),b1=path(sb,lcab),b2=path(tb,lcab);
        static bool booka[N],bookb[N];
        for(int p:a1)
            booka[p]=true;
        for(int p:a2)
            booka[p]=true;
        for(int p:b1)
            bookb[p]=true;
        for(int p:b2)
            bookb[p]=true;
        int res=INF,pos=0;
        for(int i=1;i<=n;i++)
            if(booka[i]&&bookb[i])
            {
                int a=(dep[sa]+dep[ta]-dep[lcaa]*2)*2,c1=dis(sa,lcaa,i),c2=(dep[sa]+dep[ta]-dep[lcaa]*2)+dis(ta,lcaa,i);
                int b=-(dep[sb]+dep[tb]-dep[lcab]*2)*2,c3=dis(sb,lcab,i),c4=(dep[sb]+dep[tb]-dep[lcab]*2)+dis(tb,lcab,i);
                for(int ac:{c1,c2})
                    for(int bc:{c3,c4})
                    {
                        int c=bc-ac;
                        int x,y;
                        if(calc(a,b,c,x,y))
                        {
                            if(a*x+ac<res) res=a*x+ac,pos=i;
                        }
                    }
            }
        for(int p:a1)
            booka[p]=false;
        for(int p:a2)
            booka[p]=false;
        for(int p:b1)
            bookb[p]=false;
        for(int p:b2)
            bookb[p]=false;
        if(res>=INF) cout<<"-1\n";
        else cout<<pos<<"\n";
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
