#include<iostream>
#include<cstdio>
#include<set>
#include<tuple>
#include<vector>
#include<numeric>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n,Q,s,d;
int a[N];
int fa[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    else return fa[v]=getf(fa[v]);
}
void merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2) fa[f2]=f1;
    return;
}
vector<pair<int,int>>G[N];
void boruvka()
{
    iota(fa+1,fa+n+1,1);
    set<pair<int,int>>S;
    for(int i=1;i<=n;i++)
        S.insert({a[i],i});
    int tot=n;
    while(tot>1)
    {
        static vector<int> block[N];
        for(int i=1;i<=n;i++)
            block[i].clear();
        for(int i=1;i<=n;i++)
            block[getf(i)].emplace_back(i);
        static tuple<int,int,int> mi[N];
        fill(mi+1,mi+n+1,make_tuple(INF,0,0));
        for(int r=1;r<=n;r++)
            if(getf(r)==r)
            {
                for(int u:block[r])
                    S.erase(S.find({a[u],u}));
                for(int i:block[r])
                {
                    set<pair<int,int>>::iterator it;
                    it=S.lower_bound({a[i]-d,0});
                    if(it!=S.end())
                    {
                        int j=it->second;
                        if(a[i]>=a[j]) mi[r]=min(mi[r],{abs(d-abs(a[i]-a[j])),i,j});
                    }
                    if(it!=S.begin())
                    {
                        it--;
                        int j=it->second;
                        if(a[i]>=a[j]) mi[r]=min(mi[r],{abs(d-abs(a[i]-a[j])),i,j});
                    }
                    it=S.lower_bound({a[i]+d,0});
                    if(it!=S.end())
                    {
                        int j=it->second;
                        if(a[i]<=a[j]) mi[r]=min(mi[r],{abs(d-abs(a[i]-a[j])),i,j});
                    }
                    if(it!=S.begin())
                    {
                        it--;
                        int j=it->second;
                        if(a[i]<=a[j]) mi[r]=min(mi[r],{abs(d-abs(a[i]-a[j])),i,j});
                    }
                }
                for(int u:block[r])
                    S.insert({a[u],u});
            }
        for(int i=1;i<=n;i++)
            if(getf(i)==i)
            {
                auto [w,v,u]=mi[i];
                if(getf(u)!=getf(v))
                {
                    G[u].emplace_back(v,w);
                    G[v].emplace_back(u,w);
                    tot--;
                    merge(u,v);
                }
            }
    }
    return;
}
int mx[N];
void dfs(int u,int father)
{
    for(auto [v,w]:G[u])
    {
        if(v==father) continue;
        mx[v]=max(mx[u],w);
        dfs(v,u);
    }
    return;
}
int main()
{
    scanf("%d%d%d%d",&n,&Q,&s,&d);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    boruvka();
    dfs(s,0);
    while(Q--)
    {
        int i,k;
        scanf("%d%d",&i,&k);
        if(mx[i]>k) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}