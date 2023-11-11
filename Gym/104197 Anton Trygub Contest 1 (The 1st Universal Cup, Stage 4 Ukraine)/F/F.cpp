#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=20005;
int n,m;
vector<int>G[N],f[N];
int id[N],rk[N];
int deg[N];
int c[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    n*=2;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    for(int i=1;i<=n;i++)
        deg[i]=G[i].size(),id[i]=i;
    sort(id+1,id+n+1,[=](const int &x,const int &y){return deg[x]!=deg[y]?deg[x]<deg[y]:x<y;});
    for(int i=1;i<=n;i++) rk[id[i]]=i;
    for(int u=1;u<=n;u++)
        for(int v:G[u]) 
            if(rk[v]>rk[u]) f[u].push_back(v);
    long long ans=0;
    for(int u=1;u<=n;u++)
    {
        for(int v:G[u])
            for(int w:f[v])
                if(rk[w]>rk[u]) ans+=c[w],c[w]++;
        for(int v:G[u])
            for(int w:f[v])
                if(rk[w]>rk[u]) c[w]=0;
    }
    if(ans) cout<<2;
    else cout<<3;
    return 0;
}