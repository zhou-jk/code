#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=100005;
int n,m;
vector<int>G[N];
int fa[N],siz[N];
bool vis[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    else return fa[v]=getf(fa[v]);
}
void merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2) fa[f1]=f2,siz[f2]+=siz[f1];
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
    }
    for(int i=1;i<=n;i++)
        fa[i]=i,siz[i]=1;
    for(int u=1;u<=n;u++)
        for(int i=1;i<(int)G[u].size();i++)
            merge(G[u][0],G[u][i]);
    queue<int>q;
    for(int i=1;i<=n;i++)
        if(siz[getf(i)]>1)
        {
            q.emplace(i);
            vis[i]=true;
        }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:G[u])
        {
            merge(u,v);
            if(!vis[v])
            {
                q.emplace(v);
                vis[v]=true;
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        if(getf(i)==i)
        {
            if(siz[i]==1) ans+=G[i].size();
            else ans+=(long long)siz[i]*(siz[i]-1);
        }
    printf("%lld",ans);
    return 0;
}