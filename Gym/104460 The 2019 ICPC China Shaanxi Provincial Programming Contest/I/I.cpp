#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
int n;
vector<pair<int,char>>G[N];
int dfn[N],siz[N],Index;
void dfs(int u,int father)
{
    dfn[u]=++Index;
    siz[u]=1;
    for(auto [v,c]:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
    return;
}
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        char z;
        cin>>x>>y>>z;
        G[x].emplace_back(y,z);
        G[y].emplace_back(x,z);
    }
    Index=0;
    dfs(1,0);
    fill(a+1,a+n+1,0);
    int tot=0;
    for(int u=1;u<=n;u++)
    {
        vector<int> pos[26];
        for(auto [v,c]:G[u])
            pos[c-'a'].emplace_back(v);
        int cnt=0;
        for(int c=0;c<26;c++)
            if((int)pos[c].size()>2)
            {
                cout<<0<<"\n";
                return;
            }
            else if((int)pos[c].size()==2)
            {
                cnt++;
                tot++;
                if(cnt>=2)
                {
                    cout<<0<<"\n";
                    return;
                }
                int x=pos[c][0],y=pos[c][1];
                if(dfn[u]<dfn[x]&&dfn[u]<dfn[y])
                {
                    a[dfn[x]]++,a[dfn[x]+siz[x]]--;
                    a[dfn[y]]++,a[dfn[y]+siz[y]]--;
                }
                else if(dfn[x]<dfn[u]&&dfn[u]<dfn[y])
                {
                    a[dfn[y]]++,a[dfn[y]+siz[y]]--;
                    a[1]++,a[dfn[u]]--;
                    a[dfn[u]+siz[u]]++;
                }
                else if(dfn[y]<dfn[u]&&dfn[u]<dfn[x])
                {
                    a[dfn[x]]++,a[dfn[x]+siz[x]]--;
                    a[1]++,a[dfn[u]]--;
                    a[dfn[u]+siz[u]]++;
                }
            }
    }
    for(int i=1;i<=n;i++)
        a[i]+=a[i-1];
    int ans=0;
    for(int i=1;i<=n;i++)
        if(a[i]==tot) ans++;
    cout<<ans<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}