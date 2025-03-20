#include<bits/stdc++.h>
using namespace std;
const int N=2505;
int n;
vector<int>G[N];
int deg[N];
void tour(int u)
{
    if((int)G[u].size()==deg[u]) return;
    int i=G[u].size();
    cout<<"> "<<i+1<<endl;
    int v,d;
    cin>>v>>d;
    G[u].emplace_back(v);
    deg[v]=d;
    tour(v);
    return;
}
bool vis[N];
void dfs(int u)
{
    tour(u);
    vis[u]=true;
    n++;
    for(int i=0;i<(int)G[u].size();i++)
    {
        int v=G[u][i];
        if(!vis[v])
        {
            cout<<"> "<<i+1<<"\n";
            int vv,dd;
            cin>>vv>>dd;
            dfs(vv);
            for(int j=0;j<(int)G[v].size();j++)
                if(G[v][j]==u)
                {
                    cout<<"> "<<j+1<<"\n";
                    int uu,dd;
                    cin>>uu>>dd;
                }
        }
    }
    return;
}
void solve()
{
    n=0;
    for(int i=1;i<=2500;i++)
        deg[i]=0,vis[i]=false,G[i].clear();
    int u;
    cin>>u;
    cin>>deg[u];
    dfs(u);
    cout<<"!";
    for(int u=1;u<=n;u++)
        for(int v:G[u])
            if(u<v) cout<<" "<<u<<" "<<v;
    cout<<endl;
    string res;
    cin>>res;
    if(res!="Correct") exit(0);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}