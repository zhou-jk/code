#include<bits/stdc++.h>
using namespace std;
constexpr int N=300005;
int n,q;
vector<int>G[N];
int fa[N][20],dep[N];
void dfs(int u)
{
    dep[u]=dep[fa[u][0]]+1;
    for(int i=1;(1<<i)<=n;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int v:G[u])
        dfs(v);
    return;
}
int lca(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=__lg(n);i>=0;i--)
        if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
    if(u==v) return u;
    for(int i=__lg(n);i>=0;i--)
        if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
int kth_ancestor(int u,int d)
{
    for(int i=__lg(n);i>=0;i--)
        if((d>>i)&1) u=fa[u][i];
    return u;
}
int p[N];
bool vis[N];
vector<int>E[N];
int deg[N]; 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>fa[i][0];
        G[fa[i][0]].emplace_back(i);
    }
    dfs(1);
    cin>>q;
    while(q--)
    {
        int m;
        cin>>m;
        for(int i=1;i<=m;i++)
            cin>>p[i];
        bool flag=true;
        for(int i=1;i<=m;i++)
            if(vis[p[i]])
            {
                flag=false;
                break;
            }
            else vis[p[i]]=true;
        vector<int>pos;
        if(flag)
        {
            for(int i=1,j=1;i<=m;i=j)
            {
                while(j<=m&&dep[p[i]]==dep[p[j]]) j++;
                if(j<=m&&dep[p[j]]<dep[p[i]])
                {
                    flag=false;
                    break;
                }
                for(int k=i;k+1<j;k++)
                {
                    int u=p[k],v=p[k+1],l=lca(u,v);
                    int lu=kth_ancestor(u,dep[u]-dep[l]-1),lv=kth_ancestor(v,dep[v]-dep[l]-1);
                    E[lu].emplace_back(lv);
                    deg[lv]++;
                    pos.emplace_back(lu);
                    pos.emplace_back(lv);
                }
            }
            sort(pos.begin(),pos.end());
            pos.erase(unique(pos.begin(),pos.end()),pos.end());
            queue<int>q;
            for(int u:pos)
                if(deg[u]==0) q.emplace(u);
            int cnt=0;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                cnt++;
                for(int v:E[u])
                {
                    deg[v]--;
                    if(deg[v]==0) q.emplace(v);
                }
            }
            if(cnt!=(int)pos.size()) flag=false;
            for(int u:pos)
                deg[u]=0,E[u].clear();
        }
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
        for(int i=1;i<=m;i++)
            vis[p[i]]=false;
    }
    return 0;
}