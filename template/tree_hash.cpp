#include<iostream>
#include<cstdio>
#include<vector>
#include<chrono>
using namespace std;
const int N=100005;
const unsigned long long mask=chrono::steady_clock::now().time_since_epoch().count();
const unsigned long long S=1;
unsigned long long shift(unsigned long long x)
{
    x^=mask;
    x^=x<<13;
    x^=x>>7;
    x^=x<<17;
    x^=mask;
    return x;
}
int n;
vector<int>G[N];
unsigned long long f[N];
void dfs(int u,int father)
{
    f[u]=S;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        f[u]+=shift(f[v]);
    }
    return;
}
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,0);
    long long s1=f[1];
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,0);
    long long s2=f[1];
    if(s1==s2) printf("Isomorphism\n");
    else printf("No\n");
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}