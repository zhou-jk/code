#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
int n,m;
vector<int>G[N];
int top[N];
int siz[N];
void dfs(int u,int father,int topf)
{
    top[u]=topf;
    siz[u]=1;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u,topf);
        siz[u]+=siz[v];
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    int sum=0;
    for(int i=1;i<=n;i++)
        if(!top[i])
        {
            dfs(i,0,i);
            if(siz[i]&1) sum^=1;
            else sum^=2;
        }
    int ans=0;
    for(int u=1;u<=n;u++)
    {
        for(int v:G[u])
            if(siz[u]<siz[v])
            {
                int val=sum;
                if(siz[top[u]]&1) val^=1;
                else val^=2;
                if(siz[u]&1) val^=1;
                else val^=2;
                if((siz[top[u]]-siz[u])&1) val^=1;
                else val^=2;
                if(val==0) ans++;
            }
        int val=sum;
        if(siz[top[u]]&1) val^=1;
        else val^=2;
        for(int v:G[u])
            if(siz[v]<siz[u])
            {
                if(siz[v]&1) val^=1;
                else val^=2;
            }
            else
            {
                if((siz[top[u]]-siz[u])&1) val^=1;
                else val^=2;
            }
        if(val==0) ans++;
    }
    cout<<ans;
    return 0;
}