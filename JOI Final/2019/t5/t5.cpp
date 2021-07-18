#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
const int N=200005;
int n,m;
vector<int>G[N];
int c[N];
int dep[N];
int s,t;
void dfs1(int u,int father)
{
    dep[u]=dep[father]+1;
    if(dep[u]>dep[s]) s=u;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs1(v,u);
    }
    return;
}
void dfs2(int u,int father)
{
    dep[u]=dep[father]+1;
    if(dep[u]>dep[t]) t=u;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs2(v,u);
    }
    return;
}
int Max[N],son[N],sson[N];
void dfs3(int u,int father)
{
    dep[u]=dep[father]+1;
    Max[u]=dep[u];
    son[u]=sson[u]=0;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs3(v,u);
        Max[u]=max(Max[u],Max[v]);
        if(Max[v]>Max[son[u]]) son[u]=v;
    }
    for(int v:G[u])
    {
        if(v==father) continue;
        if(v==son[u]) continue;
        if(Max[v]>Max[sson[u]]) sson[u]=v;
    }
    return;
}
int tot;
int cnt[N];
void add(int u)
{
    if(cnt[c[u]]==0) tot++;
    cnt[c[u]]++;
    return;
}
void del(int u)
{
    cnt[c[u]]--;
    if(cnt[c[u]]==0) tot--;
    return;
}
stack<int>stk;
int ans[N];
void dfs4(int u,int father)
{
    if(son[u])
    {
        vector<int>tss,ts;
        while(!stk.empty()&&dep[u]-dep[stk.top()]<=Max[sson[u]]-dep[u]) tss.emplace_back(stk.top()),del(stk.top()),stk.pop();
        add(u),stk.emplace(u);
        dfs4(son[u],u);
        while(!stk.empty()&&dep[u]-dep[stk.top()]<=Max[son[u]]-dep[u]) ts.emplace_back(stk.top()),del(stk.top()),stk.pop();
        ans[u]=max(ans[u],tot);
        for(int v:G[u])
        {
            if(v==father||v==son[u]) continue;
            if(stk.empty()||stk.top()!=u) add(u),stk.emplace(u);
            dfs4(v,u);
        }
        if(!stk.empty()&&stk.top()==u)
        {
            del(u);
            stk.pop();
        }
    }
    else ans[u]=max(ans[u],tot);
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    dfs1(1,0);
    dfs2(s,0);
    dfs3(s,0);
    dfs4(s,0);
    dfs3(t,0);
    dfs4(t,0);
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}