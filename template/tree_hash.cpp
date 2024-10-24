#include<iostream>
#include<cstdio>
#include<vector>
#include<chrono>
#include<random>
using namespace std;
const int N=1000005;
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,0);
    vector<unsigned long long>val;
    for(int i=1;i<=n;i++)
        val.emplace_back(f[i]);
    sort(val.begin(),val.end());
    val.erase(unique(val.begin(),val.end()),val.end());
    int ans=val.size();
    cout<<ans;
    return 0;
}
