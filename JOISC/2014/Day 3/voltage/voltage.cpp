#include<iostream>
#include<cstdio>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=100005,M=200005;
int n,m;
int x[M],y[M];
vector<pair<int,int>>G[N];
bool vis[N],book[M];
int dep[N];
int s[N];
int fa[N];
void dfs(int u)
{
    vis[u]=true;
    for(auto [v,i]:G[u])
    {
        if(vis[v]) continue;
        book[i]=true;
        fa[v]=u;
        dep[v]=dep[u]+1;
        dfs(v);
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        G[x[i]].emplace_back(y[i],i);
        G[y[i]].emplace_back(x[i],i);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]) dfs(i);
    int cnt=0;
    for(int u=1;u<=n;u++)
        for(auto [v,i]:G[u])
            if(u<v)
            {
                if(book[i]) continue;
                int a=u,b=v;
                if(dep[a]<dep[b]) swap(a,b);
                if((dep[a]-dep[b])%2==0) s[a]++,s[b]--,cnt++;
                else s[a]--,s[b]++;
            }
    static int id[N];
    iota(id+1,id+n+1,1);
    sort(id+1,id+n+1,[=](const int &x,const int &y){return dep[x]>dep[y];});
    for(int i=1;i<=n;i++)
        s[fa[id[i]]]+=s[id[i]];
    int ans=0;
    for(int i=1;i<=m;i++)
        if(book[i])
        {
            int u=x[i],v=y[i];
            if(dep[u]<dep[v]) swap(u,v);
            if(s[u]==cnt) ans++;
        }
    if(cnt==1) ans++;
    printf("%d",ans);
    return 0;
}