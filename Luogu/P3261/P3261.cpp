#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=300005;
int n,m;
vector<int>G[N],e[N];
int c[N],a[N];
long long h[N],v[N];
struct Node
{
    int lc,rc,dis;
    long long val,lazyadd,lazymul;
}tree[N];
int dep[N],dead[N],up[N];
void add(int u,long long c,long long j)
{
    if(!u) return;
    tree[u].val*=c,tree[u].val+=j;
    tree[u].lazymul*=c;
    tree[u].lazyadd*=c,tree[u].lazyadd+=j;
    return;
}
void push_down(int u)
{
    add(tree[u].lc,tree[u].lazymul,tree[u].lazyadd);
    add(tree[u].rc,tree[u].lazymul,tree[u].lazyadd);
    tree[u].lazymul=1;
    tree[u].lazyadd=0;
}
int merge(int u,int v)
{
    if(!u) return v;
    if(!v) return u;
    if(tree[u].val>tree[v].val) swap(u,v);
    push_down(u);
    push_down(v);
    tree[u].rc=merge(tree[u].rc,v);
    if(tree[tree[u].lc].dis<tree[tree[u].rc].dis) swap(tree[u].lc,tree[u].rc);
    tree[u].dis=tree[tree[u].rc].dis+1;
    return u;
}
int pop(int u)
{
    push_down(u);
    return merge(tree[u].lc,tree[u].rc);
}
int dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    int A=0,B;
    for(auto v:e[u])
        A=merge(A,v);
    for(auto v:G[u])
    {
        B=dfs(v,u);
        A=merge(A,B);
    }
    while(tree[A].val<h[u]&&A)
    {
        up[A]=dep[u];
        dead[u]++;
        A=pop(A);
    }
    if(a[u]) add(A,v[u],0);
    else add(A,1,v[u]);
    return A;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&h[i]);
    for(int i=2;i<=n;i++)
    {
        int f;
        scanf("%d%d%lld",&f,&a[i],&v[i]);
        G[f].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%lld%d",&tree[i].val,&c[i]);
        e[c[i]].push_back(i);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        printf("%d\n",dead[i]);
    for(int i=1;i<=m;i++)
        printf("%d\n",dep[c[i]]-up[i]);
    return 0;
}