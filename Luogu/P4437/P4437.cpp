#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=500001;
int n,tot;
int f[N],s[N];
long long w[N];
struct Node
{
    int id,size;
    long long val;
    bool operator>(const Node &b)const
    {
        return val*b.size>b.val*size;
    }
};
priority_queue<Node,vector<Node>,greater<Node> >q;
int fa[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    fa[v]=getf(fa[v]);
    return fa[v];
}
vector<int>e[N];
bool vis[N];
void dfs(int u,int father)
{
    vis[u]=true;
    tot++;
    for(auto v:e[u])
    {
        if(v==father) continue;
        if(vis[v])
        {
            printf("-1");
            exit(0);
        }
        dfs(v,u);
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        fa[i]=i,s[i]=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&f[i]);
        e[f[i]].push_back(i);
    }
    dfs(0,-1);
    if(tot<n)
    {
        printf("-1");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&w[i]);
        q.push((Node){i,1,w[i]});
    }
    long long ans=0;
    while(!q.empty())
    {
        Node t=q.top();
        q.pop();
        int u=getf(t.id);
        if(s[u]!=t.size) continue;
        fa[u]=getf(f[u]); 
        ans+=w[u]*s[fa[u]],s[fa[u]]+=s[u],w[fa[u]]+=w[u];
        if(fa[u]) q.push((Node){fa[u],s[fa[u]],w[fa[u]]});
    }
    printf("%lld",ans);
    return 0;
}