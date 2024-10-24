#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=500005;
int n,q;
vector<int>G[N];
int dfn[N],Index;
int mn[N][20],lg2[N];
void dfs(int u,int father)
{
    dfn[u]=++Index;
    mn[Index][0]=father;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
    }
    return;
}
int lca(int u,int v)
{
    if(u==v) return u;
    u=dfn[u],v=dfn[v];
    if(u>v) swap(u,v);
    u++;
    int d=lg2[v-u+1];
    if(dfn[mn[u][d]]<dfn[mn[v-(1<<d)+1][d]]) return mn[u][d];
    else return mn[v-(1<<d)+1][d];
}
vector<int>E[N];
void build(vector<int>h)
{
    sort(h.begin(),h.end(),[&](const int &x,const int &y){return dfn[x]<dfn[y];});
    static int s[N],top;
    top=0;
    s[++top]=1;
    E[1].clear();
    for(int i=0;i<(int)h.size();i++)
        if(h[i]!=1)
        {
            int l=lca(h[i],s[top]);
            if(l!=s[top])
            {
                while(dfn[l]<dfn[s[top-1]])
                {
                    E[s[top]].emplace_back(s[top-1]),E[s[top-1]].emplace_back(s[top]);
                    top--;
                }
                if(dfn[l]>dfn[s[top-1]])
                {
                    E[l].clear();
                    E[l].emplace_back(s[top]),E[s[top]].emplace_back(l);
                    top--;
                    s[++top]=l;
                }
                else
                {
                    E[s[top-1]].emplace_back(s[top]),E[s[top]].emplace_back(s[top-1]);
                    top--;
                }
            }
            E[h[i]].clear();
            s[++top]=h[i];
        }
    for(int i=1;i<top;i++)
        E[s[i]].emplace_back(s[i+1]),E[s[i+1]].emplace_back(s[i]);
    return;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs(1,0);
    lg2[0]=-1;
    for(int i=1;i<=n;i++)
        lg2[i]=lg2[i/2]+1;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            if(dfn[mn[i][j-1]]<dfn[mn[i+(1<<(j-1))][j-1]]) mn[i][j]=mn[i][j-1];
            else mn[i][j]=mn[i+(1<<(j-1))][j-1];
    return 0;
}