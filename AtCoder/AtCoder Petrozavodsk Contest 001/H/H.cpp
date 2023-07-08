#include<iostream>
#include<cstdio>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2005;
int n;
int a[N];
set<int>son[N];
int fa[N],dep[N];
int col[N];
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    for(int v:son[u])
    {
        if(v==father) continue;
        dfs(v,u);
    }
    return;
}
vector<int>ans;
void rotate(int v)
{
    vector<int>pos;
    for(int u=v;u!=1;u=fa[u])
        pos.emplace_back(u);
    reverse(pos.begin(),pos.end());
    int c=a[1];
    for(int u:pos)
        a[fa[u]]=a[u];
    a[v]=c;
    ans.emplace_back(v);
    return;
}
void del(int v)
{
    col[v]=-1;
    if(v==1) return;
    son[fa[v]].erase(son[fa[v]].find(v));
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&fa[i]);
        fa[i]++;
        son[fa[i]].insert(i);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]++;
    }
    dfs(1,0);
    queue<int>q;
    for(int i=1;i<=n;i++)
        if(son[i].size()==0&&a[i]==i) q.emplace(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u==1) break;
        del(u);
        if(son[fa[u]].size()==0&&a[fa[u]]==fa[u]) q.emplace(fa[u]);
    }
    for(int i=1;i<=n;i++)
        if(col[i]!=-1&&son[i].size()==0) q.emplace(i);
    while(!q.empty())
    {
        int u=q.front();
        col[u]=1;
        q.pop();
        if(col[fa[u]]!=-1&&son[fa[u]].size()==1) q.emplace(fa[u]);
    }
    while((int)son[1].size()>0)
    {
        if(col[a[1]]==1)
        {
            vector<int>pos;
            for(int u=a[1];(int)son[u].size()>=1;)
            {
                u=*son[u].begin();
                if(col[u]==-1) break;
                pos.emplace_back(u);
            }
            reverse(pos.begin(),pos.end());
            for(int u=a[1];u!=1;u=fa[u])
                pos.emplace_back(u);
            pos.emplace_back(1);
            static bool vis[N];
            for(int u:pos)
                vis[u]=true;
            int v=pos[0];
            for(int u:pos)
                if(!vis[a[u]]||dep[a[u]]<dep[a[1]])
                {
                    v=u;
                    break; 
                }
            for(int u:pos)
                vis[u]=false;
            rotate(v);
            if(son[v].size()==0&&a[v]==v)
            {
                del(v);
                bool flag=true;
                for(int u=fa[v];u;u=fa[u])
                {
                    if(son[u].size()==0&&a[u]==u&&flag) del(u);
                    else if(son[u].size()==0||(son[u].size()==1&&col[*son[u].begin()]==1)) col[u]=1,flag=false;
                    else break;
                }
            }
        }
        else
        {
            int v=0;
            for(int i=1;i<=n;i++)
                if(col[a[i]]==1&&son[a[i]].size()==0&&dep[i]>dep[v]) v=i;
            rotate(v);
        }
    }
    int Q=ans.size();
    printf("%d\n",Q);
    for(int v:ans)
        printf("%d\n",v-1);
    return 0;
}